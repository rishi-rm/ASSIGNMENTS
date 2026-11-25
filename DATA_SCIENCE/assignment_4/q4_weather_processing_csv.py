import csv
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent
INPUT_FILE = BASE_DIR / "data" / "weather.csv"
OUTPUT_FILE = BASE_DIR / "outputs" / "q4_city_weather_statistics.csv"


def main():
    with INPUT_FILE.open("r", newline="", encoding="utf-8") as file:
        records = list(csv.DictReader(file))
    if not records:
        print("No weather records found.")
        return

    city_data = {}
    for record in records:
        city = record["City"]
        city_data.setdefault(city, []).append(record)

    print("\nCity-Wise Weather Statistics:")
    statistics = []
    for city, data in city_data.items():
        temperatures = [float(row["Temperature"]) for row in data]
        humidities = [float(row["Humidity"]) for row in data]
        avg_temperature = sum(temperatures) / len(temperatures)
        avg_humidity = sum(humidities) / len(humidities)
        row = {
            "City": city,
            "Average_Temperature": round(avg_temperature, 2),
            "Maximum_Temperature": max(temperatures),
            "Minimum_Temperature": min(temperatures),
            "Average_Humidity": round(avg_humidity, 2),
        }
        statistics.append(row)
        print(row)

    rainiest = max(records, key=lambda row: float(row["Rainfall"]))
    rainy_days = sum(float(row["Rainfall"]) > 0 for row in records)
    humidity_above_70 = [row["City"] for row in statistics if row["Average_Humidity"] > 70]
    print("\nDay with maximum rainfall:", rainiest["Date"], rainiest["City"], "-", rainiest["Rainfall"])
    print("Rainy days:", rainy_days)
    print("Cities with average humidity above 70%:", ", ".join(humidity_above_70) if humidity_above_70 else "None")

    OUTPUT_FILE.parent.mkdir(parents=True, exist_ok=True)
    with OUTPUT_FILE.open("w", newline="", encoding="utf-8") as file:
        writer = csv.DictWriter(file, fieldnames=["City", "Average_Temperature", "Maximum_Temperature", "Minimum_Temperature", "Average_Humidity"])
        writer.writeheader()
        writer.writerows(statistics)
    print("\nCity-wise statistics saved to:", OUTPUT_FILE)


if __name__ == "__main__":
    main()
