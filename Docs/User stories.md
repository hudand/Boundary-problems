Пользовательские сценарии

1.  Решение краевой задачи (расширенный набор опций)
- Пользователь выбирает способ ввода дифференциального уравнения и краевых условий (выбор из списка на форме; запись уравнения и краевых условий в окне (окнах) по определенному синтаксису; выбор из текстового файла; выбор из базы данных);
- Пользователь вводит дифференциальное уравнение;
- Пользователь вводит краевые условия;
- Пользователь вводит число узлов сетки;
- Пользователь выбирает тип сетки узлов (равномерная / неравномерная);
- Пользователь вводит число узлов аппроксимации производных;
- Пользователь вводит начальное приближение к решению;
- Пользователь выбирает метод решения алгебраической нелинейной системы уравнений;
- Пользователь выбирает метод решения системы линейных алгебраических уравнений (СЛАУ);
- Пользователь выбирает способ регуляризации;
- Пользователь выбирает способ вывода результатов (на форму; в текстовый файл);
- Пользователь включает (выключает) вывод графика на экран;
- Пользователь запускает решение;
- Пользователь видит результаты.

2.  Решение краевой задачи (минимальный набор опций)
- Пользователь выбирает способ ввода дифференциального уравнения и краевых условий (выбор из списка на форме; запись уравнения и краевых условий в окне (окнах) по определенному синтаксису; выбор из текстового файла; выбор из базы данных);
- Пользователь вводит дифференциальное уравнение;
- Пользователь вводит краевые условия;
- Пользователь выбирает способ вывода результатов (на форму; в текстовый файл);
- Пользователь включает (выключает) вывод графика на экран;
- Пользователь запускает решение;
- Пользователь видит результаты.

3.  Настройка сетки узлов
- Пользователь выбирает способ ввода сетки узлов (в случае неравномерной сетки: ввод числового вектора из источника ввода; ввод по формуле);
- Пользователь выбирает источник ввода числового вектора;
- Пользователь выбирает или вводит формулу для вычисления узлов.
 
4.  Настройки метода решения нелинейной системы уравнений
- Пользователь определяет точность решения системы;
- Пользователь вводит (если нужно) числовые параметры метода;
- Пользователь определяет максимальное количество итераций (после этого количества итераций метод решения нелинейной системы останавливается, даже если система не решена с нужной точностью);
- Пользователь вводит уровень разболтки процесса (если норма || f(x) || становится больше порогового значения, то процесс останавливается).

5.  Настройки метода регуляризации
- Пользователь вводит значения числовых параметров регуляризации (альфа и альфа1).

6.  Настройка начального приближения
- Пользователь выбирает способ ввода начального приближения (табулирование по заданной формуле или считывание с какого-либо источника ввода числового вектора);
- Пользователь вводит формулу (при первом способе ввода);
- Пользователь выбирает источник ввода вектора (при втором способе ввода).

7.  Восстановление сеточного решения в аналитическом виде
- Пользователь выбирает метод аппроксимации сеточного решения;
- Пользователь вводит настройки конкретного метода аппроксимации;
- Пользователь выбирает формулу расчета невязки между левой и правой частями дифференциального уравнения;
- Пользователь запускает процесс восстановления;
- Пользователь видит результаты (невязка).


На мой взгляд, одним из удобств является сохранение последних введенных значений в настройках, т.е. при повторном запуске программы настройки примут значения предыдущего запуска. Также можно сделать сброс настроек к оптимальным, на мой взгляд, значениям.

В дальнейшем планируется добавить пользовательские сценарии, связанные с распараллеливанием процессов. Пока тщательно это не продумывал. 


8.  Авторизация и сохранение пользовательских настроек
- Пользователь вводит логин;
- Пользователь вводит пароль;
- При успешной авторизации значения настроек системы инициализируются значениями, сохраненными текущим пользователем при последнем запуске;
- При выходе из приложения пользователю предлагается сохранить текущие настройки.

Примечание: пользователь системы может не проходить авторизацию. Тогда настройки системы инициализируются значениями по умолчанию.


