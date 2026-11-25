import csv
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent
INPUT_FILE = BASE_DIR / "data" / "movies.csv"
OUTPUT_FILE = BASE_DIR / "outputs" / "q5_top_rated_movies.csv"


def main():
    with INPUT_FILE.open("r", newline="", encoding="utf-8") as file:
        movies = list(csv.DictReader(file))
    if not movies:
        print("No movie records found.")
        return

    for movie in movies:
        movie["Rating"] = float(movie["Rating"])
        movie["Votes"] = int(movie["Votes"])
        movie["Year"] = int(movie["Year"])

    highest = max(movies, key=lambda row: row["Rating"])
    print("\nHighest-Rated Movie:", highest["Title"], "-", highest["Rating"])

    top_10 = sorted(movies, key=lambda row: (row["Rating"], row["Votes"]), reverse=True)[:10]
    print("\nTop 10 Movies:")
    for movie in top_10:
        print(f"{movie['Title']} - {movie['Rating']}")

    genre_ratings = {}
    year_counts = {}
    genre_counts = {}
    for movie in movies:
        genre = movie["Genre"]
        genre_ratings.setdefault(genre, []).append(movie["Rating"])
        genre_counts[genre] = genre_counts.get(genre, 0) + 1
        year_counts[movie["Year"]] = year_counts.get(movie["Year"], 0) + 1

    print("\nAverage Rating by Genre:")
    for genre, ratings in genre_ratings.items():
        print(f"{genre}: {sum(ratings) / len(ratings):.2f}")
    print("\nNumber of Movies Released by Year:")
    for year, count in sorted(year_counts.items()):
        print(f"{year}: {count}")
    print("\nGenres with more than 20 movies:")
    qualifying = [genre for genre, count in genre_counts.items() if count > 20]
    print(", ".join(qualifying) if qualifying else "None")

    OUTPUT_FILE.parent.mkdir(parents=True, exist_ok=True)
    with OUTPUT_FILE.open("w", newline="", encoding="utf-8") as file:
        writer = csv.DictWriter(file, fieldnames=["Movie_ID", "Title", "Genre", "Year", "Rating", "Votes"])
        writer.writeheader()
        writer.writerows(top_10)
    print("\nTop-rated movies saved to:", OUTPUT_FILE)


if __name__ == "__main__":
    main()
