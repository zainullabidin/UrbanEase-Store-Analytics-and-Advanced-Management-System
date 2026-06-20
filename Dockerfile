FROM gcc:latest AS builder
WORKDIR /usr/src/app
RUN apt-get update && apt-get install -y cmake
COPY . .
RUN cmake -S . -B build && cmake --build build

FROM debian:trixie-slim
RUN apt-get update && apt-get install -y --no-install-recommends libstdc++6 && rm -rf /var/lib/apt/lists/*
WORKDIR /usr/src/app
COPY --from=builder /usr/src/app/build/urbanease .
CMD ["./urbanease"]