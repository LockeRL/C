# Тесты для лабораторной работы №01

## Входные данные:
С плавающей точкой x и точность: х, eps

## Выходные данные:
С плавающей точкой приближенное значение, точное значение, обсолютная погрешность, относительная погрешность: closevalue, exactvalue, absolut, relative


## Позитивные тесты:
- 01 - x > 1.0
- 02 - 0.0 < x < 1.0
- 03 - x < 0.0
- 04 - eps = 0.99
- 05 - eps = 1e-10

## Негативные тесты:
- 01 - введено не число в х
- 02 - точность больше 1.0
- 03 - точность меньше 0.0
- 04 - точность введена не числом