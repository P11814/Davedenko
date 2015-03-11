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
            каждое число должно выводиться  на новой строке; при этом каждое число должно выводиться количество раз,
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
            // не совсем так. вторая строка и последующие это не продолжение предыдущей, а предыдущая, которая начинается со второго 
            // символа предыдущей строки. т.е. 2-ая строка должна начинаться с В, а у вас начинается с F
            // ИСПРАВИТЬ
            // ИСПРАВЛЕНО
            int numOfSigns = 4;
            Console.Write ("\n--- 2 ---\nEnter num of strings: ");
            A = int.Parse (Console.ReadLine ());
            Console.WriteLine ();
            string alpha_string = "ABCDEFGHIJKLMNOPQRSTUVWXYZABC";
            char [] alpha_char = alpha_string.ToCharArray ();
            for (int i = 0; i < A; i++) {                
                for (int j = 0; j < numOfSigns; j++) {
                    Console.Write ("{0} ", alpha_char [count+j]);
                    }
                count++;
                if (count==26) {
                    count=0;
                }
                Console.WriteLine ();
            }
            
            //Задание 3. Определить, является ли введенное число числом-перевертышем.
            // Почему, если я ввожу число 15, ответа никакого нет? 
            // ДОДЕЛАТЬ
            // ДОДЕЛАНО
            Console.Write ("\n--- 3 ---\nEnter value: ");
            count=0;
            Line=Console.ReadLine ();
            A=int.Parse (Line);
            B=Line.Length;
            char [] digits = Line.ToCharArray ();
            if (A>20 || A==11) {
                do {
                    if (digits [count]!=digits [B-1]) {
                        Console.WriteLine ("It`s not polindrom");
                        Console.WriteLine (digits [count]);
                        break;
                    }
                    if (digits [count]==digits [B-1]) {
                        count++;
                        B--;
                    }
                    if (count==Line.Length/2  || A==11 || A==-11) {
                        Console.WriteLine ("It`s polindrom");
                        break;
                    }
                } while (true);
            } else {
                Console.WriteLine ("It`s not polindrom");
            }

             //Задание 4. Проверка на  интервал с дополнительным условием
             //	'n' – 'e’	X кратно 7
             // ЗАЧТЕНО
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
             // ЗАЧТЕНО
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
           // пользователь должен вводить шаг, которые будет являться шагом цикла. и с таким шагом в заданном диапазоне необходимо
           // расчитать выражение
           // ПЕРЕДЕЛАТЬ
           // ПЕРЕДЕЛАНО
            Console.Write ("\n--- 6 ---\nRange from -5 to 5\nEnter value not more than 5: ");
            Line=Console.ReadLine ();
            count=int.Parse (Line);
            A = -5;
            B = 5;
            if (count<10) {

                for (int i = A; i <= B; i++) {
                    if (count*i>=A && count*i<=B) {
                        Console.Write ("{0} ", count*i);
                    }                    
                }
            }
            Console.WriteLine ();
             
          
            // Задание 7
            //Определить сумму наименьшей и наибольшей цифры в числе
            // ЗАЧТЕНО
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
            // сейчас программа выводит 100-ый член ряда, а вам надо вывести сумму всех элементов
            // ПЕРЕДЕЛАТЬ
            // ПЕРЕДЕЛАНО
            Console.Write ("Sum of 100 numbers = ");
            ulong fib=0,fib1 = 0, fib2 = 1;
            
            int NumOfFib=10;
            ulong sum=0;
                for (int i = 1; i < NumOfFib+1; i++) {
                    fib = fib2 + fib1;
                    fib2 = fib1;
                    fib1 = fib;
                    sum+=fib;
                    //Console.Write ("{0} ", fib);
                }
                Console.WriteLine ("{0} ",sum);
           //
        }
    }
}
