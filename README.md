# UrbanEase — Store Analytics and Advanced Management System

This is a C++ project I built for managing and analyzing store data. It clusters stores by location, ranks them by performance, predicts next month's sales, and spits out bar charts as HTML files you can open in a browser. The whole thing runs in Docker too.

---

## What it does

The program works with store data — each store has a name, coordinates, a manager, employees, and monthly sales/cost/customer data going back 24 months.

When you run it, it goes through these steps:

**Clustering** — Takes all the stores and groups them into two clusters based on how close they are geographically (latitude and longitude). Uses K-Means with Euclidean distance. Then it sub-clusters each group again, this time by profitability instead of location. So you end up with 4 groups total.

**Ranking** — Scores every store on a 0-1 scale using four factors: profitability (40% weight), growth rate (25%), customer count (20%), and total sales (15%). Everything gets normalized with min-max scaling so they're comparable. Then it sorts and shows the top 10 and bottom 5.

**Forecasting** — Predicts next month's sales for each store. It averages the last 4 months, adds a momentum term (basically how much sales changed over the last few months), and gives a confidence score based on how volatile the recent data has been. If confidence is low the data has been all over the place.

**Charts** — Generates HTML files with Chart.js bar graphs. One for a single store's monthly sales, one comparing profits across stores you pick, and one showing cluster-level profits. You open these in Chrome and they look way better than terminal output.

---

## How to build and run

### Locally

```bash
cmake -S . -B build
cmake --build build
./build/urbanease
```

### With Docker

```bash
docker-compose build --no-cache
docker-compose up -d web
docker-compose run app
```

After the program finishes, open the charts at:

```
localhost:8080/chart_store.html
localhost:8080/chart_comparison.html
localhost:8080/chart_clusters.html
```

To shut it all down:

```bash
docker-compose down
```

---

## Project structure

```
headers/             — all the class declarations
src/
  main.cpp           — entry point, banner, calls starter()
  stakeholder/       — Person, Employee, Manager (inheritance chain)
  stores/            — Store and Coordinates
  analytics/         — monthly sales, costs, customer counts
  cluster/           — K-Means clustering + sub-clustering
  report/            — performance ranking + sales forecast
  visualization/     — HTML chart generation
  helper/            — data loading, saving, menu, input validation
files/
  data.txt           — generated or loaded store data
  charts/            — where the HTML charts go
Dockerfile           — two-stage build (gcc → debian slim)
docker-compose.yaml  — app + nginx for serving charts
```

---

## OOP stuff used

The project covers most of the OOP concepts we learned:

- Multi-level inheritance: Person → Employee → Manager
- Operator overloading all over the place — `+`, `-`, `*`, `>`, `<`, `++`, `--`, `==`, `=`, `<<`, `[]` on the analytics and Cluster classes
- Dynamic memory for employee arrays, cluster arrays, and analytics data (manual new/delete, no smart pointers)
- Deep copy with copy constructors and assignment operators for Store and analytics
- Composition — Store has a Manager, an Employee array, Coordinates, and analytics as members
- File I/O with ifstream/ofstream for data persistence and HTML output
- Friend functions for the `<<` operators

---

## How the algorithms work

### K-Means (the clustering part)

Pick two random stores as initial centers. For each store, calculate Euclidean distance to both centers. Assign it to the closer one. Update the center as a running average. Repeat until centers stop moving (within 0.0001) or 100 iterations, whichever comes first. Then do the same thing again within each cluster, but using profitability as the distance metric instead of coordinates.

### Performance score

```
Score = 0.40 * Profitability + 0.25 * GrowthRate + 0.15 * TotalSales + 0.20 * CustomerCount
```

Each metric is normalized to [0,1] using min-max over the last 12 months of data.

### Forecast

```
Predicted = avg(last 4 months) + 0.35 * momentum
momentum = (latest month - 4 months ago) / 2
confidence = 100 - (stddev / mean) * 100   (clamped between 0 and 100)
```

The confidence basically tells you how stable the recent trend is. High confidence means the sales have been consistent, low means they've been jumping around.

---

## Docker setup

Two-stage Dockerfile: first stage uses `gcc:latest` to compile everything with CMake, second stage copies just the binary into `debian:trixie-slim` so the final image doesn't have the whole compiler in it.

docker-compose runs two services — the app itself (interactive, so you can type input) and an nginx container that serves the chart HTML files on port 8080. They share a volume so when the app writes charts to `files/charts/`, nginx can serve them immediately.

---

## Requirements

- C++17
- CMake 3.16+
- Docker and Docker Compose (if you want to run it containerized)

---

## Author

Zain ul Abidin