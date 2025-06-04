#!/bin/bash

# Получаем логи тестов из контейнера app
docker logs test-app > /usr/share/nginx/html/index.html

# Запускаем Nginx
nginx -g "daemon off;"
