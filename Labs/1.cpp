using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
ЛР_4. Классы, искл. Ситуации, пространства имен
1.	Придумать класс, описывающий студента и предусмотреть в нем следующие характеристики: фамилия, имя, отчество, группа ,
 * возраст, массив оценок (рваный) по программированию, администрированию и  дизайну. Добавить методы по работе с перечисленными данными:
 * возможность установки/получения оценки, получение среднего балла по заданному предмету, распечатка данных о студенте.
2.	Разработать собственный класс для хранения целочисленных коэффициентов А и В линейного уравнения A*X + B*Y = 0. В классе реализовать
 * статический метод Parse, которые принимает строку со значениями коэффициентов, разделенных запятой или пробелом. В случае передачи в метод
 * строки недопустимого формата генерируется исключение FormatException.
3.	Разработать метод для решения системы 2 линейных уравнений:
A1*x + B1*y = 0
A2*x + B2*y = 0
Метод с помощью выходных параметров должен возвращать найденной решение или генерирует исключение ArgumentOutOfRangeException, если решение не существует. 
4.	Разработайте приложение «7 чудес света», где каждое чудо будет представлено отдельным классом. Создайте дополнительный класс, содержащий точку входа.
 * Распределите приложение по файлам проекта и с помощью пространства имен обеспечьте возможность взаимодействия классов. 
5.	Разработать приложение, в котором бы сравнивалось население трех столиц из разных стран. Причем страна бы обозначалась пространством имен,
 * а город – классом в данном пространстве.
 * */
namespace ClassWork {
    //---------------------------------------
    class Student {
        string surname;
        string name;
        string fathersname;
        int group;
        int age;
        int[][] ArrRating = new int[3][];


        //конструктор
        public Student ( string surname_, string name_, string fathersname_, int age_, int group_ ) {
            surname = surname_;
            name = name_;
            fathersname = fathersname_;
            age = age_;
            group = group_;
            ArrRating[0] = new int[1];
            ArrRating[1] = new int[1];
            ArrRating[2] = new int[1];
        }


        // Информация о студенте
        public void StudentList ( ) {
            Console.WriteLine ( "{0} {1} {2}\nВозраст-{3}\nГруппа-{4}\n", surname, name, fathersname, age, group );
        }
        
        // дать оценку
        public void GetRate ( ) {
            Console.WriteLine ( "Выберите предмет: \n1.Программирование\n2.Администрирование\n3.Дизайн\n" );
            int subject = int.Parse ( Console.ReadLine ( ) );
            Console.WriteLine ( "Выставьте оценку:" );
            int mark = int.Parse ( Console.ReadLine ( ) );
            int StrLenght = ArrRating[subject - 1].Length;

            int[] marks = new int[StrLenght + 1];

            for ( int i = 0; i < StrLenght; ++i ) {
                marks[i] = ArrRating[subject - 1][i];
            }
            marks[StrLenght] = mark;

            ArrRating[subject - 1] = new int[StrLenght + 1];

            for ( int i = 0; i < StrLenght + 1; ++i ) {
                ArrRating[subject - 1][i] = marks[i];
            }
        }


        // средняя оценка
        public void MiddleMark ( ) {
            Console.WriteLine ( "Выберите предмет: \n1.Программирование\n2.Администрирование\n3.Дизайн\n" );
            int subject = int.Parse ( Console.ReadLine ( ) );
            int StrLenght = ArrRating[subject - 1].Length;
            int sum = 0, count = 0;
            for ( int i = 0; i < StrLenght; ++i ) {
                sum += ArrRating[subject - 1][i];
                count++;
            }
            count--;
            Console.WriteLine ( "Средняя оценка за предмет - {0}\n\n", sum / count );

        }


        // показать оценки
        public void ShowMarks ( ) {
            Console.WriteLine ( "Выберите предмет: \n1.Программирование\n2.Администрирование\n3.Дизайн\n" );
            int subject = int.Parse ( Console.ReadLine ( ) );
            int x = ArrRating[subject - 1].Length;
            if ( x == 1 ) {
                Console.WriteLine ( "Нет оценок\n" );
            } else {
                for ( int i = 1; i < ArrRating[subject - 1].Length; i++ ) {
                    Console.Write ( "{0} ", ArrRating[subject - 1][i], x );
                }
                Console.WriteLine ( );
            }
        }
   
    }// end class Student
    



    class Program {
        static void Main ( string[] args ) {
            int value = 1;

            Student student1 = new Student ( "Gates", "Bill", "Adamovich", 25, 118 );

            while ( value != 0 ) {

                Console.WriteLine ( "1. Информация о студенте\n2. Выставить оценку\n3. Просмотреть оценки\n4. Средняя оценка\n0. Выход\n------------------------" );
                value = int.Parse ( Console.ReadLine ( ) );// парсим значение в инт
                Console.WriteLine ( );

                switch ( value ) {
                    case 0:
                    break;
                    case 1:
                    student1.StudentList ( );
                    break;
                    case 2:
                    student1.GetRate ( );
                    break;
                    case 3:
                    student1.ShowMarks ( );
                    break;
                    case 4:
                    student1.MiddleMark ( );
                    break;
                    default:
                    Console.Write ( "Wrong!\n" );
                    break;
                }
            }
        }//   end main  

    }// end class Programm

}// end namecpase Classwork
