#!/bin/bash

# Получаем имя пода с тестами
APP_POD=$(kubectl get pods -l app=candle-app -o jsonpath="{.items[0].metadata.name}")

# Получаем логи и сохраняем в HTML
kubectl logs $APP_POD > /usr/share/nginx/html/index.html

# Запускаем Nginx
nginx -g "daemon off;"
