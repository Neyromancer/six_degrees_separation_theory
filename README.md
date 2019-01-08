# six_degrees_separation_theory
1. Добавление нового пользователя.
2. Удаление пользователя.
3. Добавление связи между 2мя пользователями.
4. Удаление связи между 2мя пользователями.
5. Получение списка всех пользователей с указанным пользователем и заданной
глубинной.
6. Метод для определения есть ли связь меду 2мя пользователями.
7. Метод проверяющий теорию 6 рукопожатий.
-------------------------------------------------------------------------------
</br>
Разработать юнит тесты на методы данного класса, а также разработать нагрузочный
тест , проверящий правильность работы данного класса в многопоточной среде.
Например: пусть есть N потоков произвольно выполняющих операции
Добавления/Удаления пользователей и Добавления/Удаления связей между ними, с
произвольным интервалом от 200 мс до 1 сек. И пусть есть поток проверяющий
выполнение теории 6 рукопожатий с интервалом в 1 сек.
