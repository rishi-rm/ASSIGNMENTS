import csv
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent
INPUT_FILE = BASE_DIR / "data" / "sales.csv"
OUTPUT_FILE = BASE_DIR / "outputs" / "q3_sales_summary.csv"


def main():
    with INPUT_FILE.open("r", newline="", encoding="utf-8") as file:
        orders = list(csv.DictReader(file))
    if not orders:
        print("No sales records found.")
        return

    product_quantity = {}
    product_revenue = {}
    region_revenue = {}
    category_sales = {}
    for order in orders:
        quantity = int(order["Quantity"])
        revenue = quantity * float(order["Price"])
        order["Total_Sales"] = revenue
        product = order["Product"]
        category = order["Category"]
        region = order["Region"]
        product_quantity[product] = product_quantity.get(product, 0) + quantity
        product_revenue[product] = product_revenue.get(product, 0) + revenue
        region_revenue[region] = region_revenue.get(region, 0) + revenue
        category_sales[category] = category_sales.get(category, 0) + revenue

    best_quantity = max(product_quantity, key=product_quantity.get)
    max_revenue_product = max(product_revenue, key=product_revenue.get)
    print("\nBest-Selling Product by Quantity:", best_quantity, "-", product_quantity[best_quantity])
    print("Product with Maximum Revenue:", max_revenue_product, "-", f"{product_revenue[max_revenue_product]:.2f}")

    print("\nRegion-Wise Revenue:")
    for region, revenue in region_revenue.items():
        print(f"{region}: {revenue:.2f}")
    print("\nCategory-Wise Sales:")
    for category, sales in category_sales.items():
        print(f"{category}: {sales:.2f}")

    top_orders = sorted(orders, key=lambda row: row["Total_Sales"], reverse=True)[:5]
    print("\nTop 5 Orders:")
    for order in top_orders:
        print(f"{order['Order_ID']} - {order['Product']}: {order['Total_Sales']:.2f}")

    OUTPUT_FILE.parent.mkdir(parents=True, exist_ok=True)
    with OUTPUT_FILE.open("w", newline="", encoding="utf-8") as file:
        writer = csv.writer(file)
        writer.writerow(["Metric", "Name", "Value"])
        writer.writerow(["Best-Selling Product", best_quantity, product_quantity[best_quantity]])
        writer.writerow(["Maximum-Revenue Product", max_revenue_product, product_revenue[max_revenue_product]])
        for region, revenue in region_revenue.items():
            writer.writerow(["Region Revenue", region, revenue])
        for category, sales in category_sales.items():
            writer.writerow(["Category Sales", category, sales])
        for order in top_orders:
            writer.writerow(["Top Order", order["Order_ID"], order["Total_Sales"]])
    print("\nSales summary saved to:", OUTPUT_FILE)


if __name__ == "__main__":
    main()
