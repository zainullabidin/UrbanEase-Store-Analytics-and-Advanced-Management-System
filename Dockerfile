FROM gcc:latest AS builder
WORKDIR /usr/src/app
RUN apt-get update && apt-get install -y cmake
COPY . .
RUN cmake -S . -B build && cmake --build build

FROM alpine:latest
RUN apk add --no-cache libstdc++
WORKDIR /usr/src/app
COPY --from=builder /usr/src/app/build/urbanease . 
COPY --from=builder /usr/src/app/files ./files
CMD ["./urbanease"]