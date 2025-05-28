## Laboratory work V 

## Курмаев Иван ИУ8-23


## Homework

### Задание
1. Создайте `CMakeList.txt` для библиотеки *banking*.
2. Создайте модульные тесты на классы `Transaction` и `Account`.
    * Используйте mock-объекты.
    * Покрытие кода должно составлять 100%.
3. Настройте сборочную процедуру на **TravisCI**.
4. Настройте [Coveralls.io](https://coveralls.io/).

## P.S.
Из-за того, что понимание того, как работают mock-объекты, пришло позже написания обычных gtest-тестов для Transaction и Account, то для Account есть обе версии тестов: и mock, и gtest.

### План выполненяия:
1. Создаем CMakeLists в banking и собираем библиотеку.
2. Подключаем gtest и gmock как submodule
3. Создаем папку tests, создаем в ней test1.cpp, в котором подключаем banking, gtest, gmock и пишем тесты
4. Добавляем в .github/workwlows deploy.yml в котором описываем установку зависимостей, сборку, подключение overalls и тесты
5. Региструемся на overalls и синхронизируем репозиторий

[![Coverage Status](https://coveralls.io/repos/github/M1nerwion/TMP_lab05/badge.svg?branch=master)](https://coveralls.io/github/M1nerwion/TMP_lab05?branch=master)
