using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;


namespace Laba_1 {
    class Program {
        static void Main ( string[] args ) {
            
            
            int A = 0, B = 0, C = 0, count = 0, count2 = 0, TmpValue = 0; ;
            int[] IntArr = new int[100];
            char[] CharArr = new char[0];
            string Line;
            
            /*Задание 1. Даны целые положительные числа А и В (A < B). Вывести все целые числа от А до В включительно;
            каждое число должно выводиться на новой строке; при этом каждое число должно выводиться количество раз,
            равное его значению (например, число 3 выводится 3 раза)*/
            
            Console.Write ( "--- 1 ---\nEnter value of   A: " );
            A = int.Parse ( Console.ReadLine ( ) );// парсим значение в инт
            Console.Write ( "Enter value of B>A: " );
            B = int.Parse ( Console.ReadLine ( ) );// парсим значение в инт
            count = A;// присваиваем значение А
            if ( A < B ) {// проверяем условие
                for ( int i = A; i <= B; i++ ) {// выводим от А до В
                    for ( int j = 0; j < count; j++ ) {// цикл на вывод значения А столько раз, сколько равно А 
                        Console.Write ( "{0}", count );// выводим А
                    }
                    Console.WriteLine ( );// каретку на начало строки троки
                    count += 1;// плюсуем А
                }
            } else { Console.WriteLine ( "Wrong value of B" ); }// если А больше В
            
            /*Задание 2.Вывести следующие строки (количество строк вводится с клавиатуры ):
                            A B C D E
                            B C D E F
                            C D E F G
                            D E F G H
                            E F G H I и т.д.
                            (Использовать тип char).*/

            int numOfSigns = 4;
            Console.Write ( "\n--- 2 ---\nEnter num of strings: " );
            A = int.Parse ( Console.ReadLine ( ) );
            Console.WriteLine ( );
            string alpha_string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            char[] alpha_char = alpha_string.ToCharArray ( );
            count = 0;
            for ( int i = 0; i < ( numOfSigns * A ); i++ ) {
                count2++;
                Console.Write ( "{0} ", alpha_char[count] );
                if ( count2 == 4 ) {
                    Console.Write ( "\n" );
                    count2 = 0;
                }
                count++;
                if ( count == 26 ) {
                    count = 0;
                }
            }
            
            //Задание 3. Определить, является ли введенное число числом-перевертышем.
            Console.Write ( "\n--- 3 ---\nEnter value >10: " );
            Line = Console.ReadLine ( );
            CharArr = new char[Line.Length];
            CharArr = Line.ToCharArray ( );
            Console.WriteLine ( );
            count = 0;
            A = Line.Length - 1;
            B = int.Parse ( Line );
            if ( B<11 ) { Console.Write ( "Hi there! Are you nut`s!!!\n" ); }
            if ( B == 11 ) { Console.Write ( "It's polindrom\n" );  }

            for ( int i = 0; i < ( A / 2 ); i++ ) {
                if ( CharArr[i] == CharArr[A - count] ) {
                    
                    if ( i == (A / 2)-1 ) {
                        Console.Write ( "It's polindrom\n" );
                    }
                } else {
                    Console.Write ( "It's not polindrom\n" );
                    break;
                } count++; 
            }

             //Задание 4. Проверка на  интервал с дополнительным условием
             //	'n' – 'e’	X кратно 7
             Console.WriteLine ( "\n--- 4 ---\n" );
             A = 'e'; B = 'n';
             Console.WriteLine ( "'e'={0} 'n'={1}",A,B );
             for ( int i = A; i < B; i++ ) {
                 if ( i % 7 == 0 ) {
                     Console.WriteLine ( "Step {0}%7=0",i );
                 }
             }
            
             //Оператор switch. Проверка на попадание в список значений
             //-3,6,99
             Console.Write ( "\n--- 5 ---\nEnter value -3, 6 or 99: " );
             A = int.Parse ( Console.ReadLine ( ) );// парсим значение в инт
               switch ( A ) {
                   case -3:
                   Console.Write ( "Right!\n" );
                   break;
                   case 6:
                   Console.Write ( "Right!\n" );
                   break;
                   case 99:
                   Console.Write ( "Right!\n" );
                   break;
                   default:
                   Console.Write ( "Wrong!\n" );
                   break;
               }
           
           //Задание 6. Операторы циклов (использовать  операторы while, do-while и for )
           //Вывести значение выражения в интервале
           //X*10	-5..5	11
            Console.WriteLine ( "\n--- 6 ---\nRange from -5 to 5" );
            A = -5; B = 5;
            for ( int i = A; i < B; i++ ) {
                if ( i * 10 > A && i * 10 < B ) {
                    Console.WriteLine ( "Step {0}*10={1}",i,i );
                }
            }
             
          
            // Задание 7
            //Определить сумму наименьшей и наибольшей цифры в числе

            Console.Write ( "\n--- 7 ---\nEnter number value: " );
            Line = Console.ReadLine ( );
            A = int.Parse ( Line );
            if ( A > 9 ) {
                count = A; count2 = 0;
                for ( int i = 0; i < Line.Length; i++ ) {
                    B = A % 10;
                    if ( B < count ) { count = B; }
                    if ( B > count2 ) { count2 = B; }
                    A /= 10;
                }
                Console.WriteLine ( "min {0} + max {1} = {2}", count, count2, count + count2 );
            } else { Console.WriteLine ( "max {0} + 0 = {0}",A,A  ); }
           
           // Задание 8
           //Рассчитать сумму чисел 100 Фибоначчи : 1, 1, 2, 3, 5, 8 ..   Xn=X(n-1)+X(n-2)

            Console.Write ( "\n--- 8 ---\n\nSum of 100 Fibonachi = " );
            decimal a=0;
            decimal b = 1;
            decimal c = 0;
            for ( int i = 0; i < 100; ++i ) {
                c = a + b; a = b; b = c;
            }
            Console.WriteLine ("{0}\n\n", b.ToString ( ) );
           
        }
    }
}
