FROM gcc:latest

# Установка зависимостей
RUN apt-get update && \
    apt-get install -y cmake libgtest-dev && \
    apt-get clean

# Копирование исходников
WORKDIR /app
COPY . .

# Сборка проекта
RUN mkdir build && cd build && \
    cmake .. && \
    make

# Запуск тестов при старте контейнера
CMD ["./build/testproj"]
