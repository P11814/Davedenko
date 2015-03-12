using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
Разработать метод для решения системы 2 линейных уравнений:
A1*x + B1*y = 0
A2*x + B2*y = 0
Метод с помощью выходных параметров должен возвращать найденной решение или генерирует исключение ArgumentOutOfRangeException, если решение не существует. 
*/
namespace ConsoleApplication3 {

    class Program {
        static void Main(string [] args) {
            int ok=0;
            int a1=0,b1=0,a2=0,b2=0,x=0,y=0;
            int tmp=0;
            Console.WriteLine (@"A1*x + B1*y = 0
A2*x + B2*y = 0");


            while(ok!=1){
                try {

                    Console.Write ("Enter value for A1>0: ");
                    a1 = int.Parse (Console.ReadLine ( ));
                    Console.Write ("Enter value for B1>0: ");
                    b1 = int.Parse (Console.ReadLine ( ));
                    Console.Write ("Enter value for A2>0: ");
                    a2 = int.Parse (Console.ReadLine ( ));
                    Console.Write ("Enter value for B2>0: ");
                    b2 = int.Parse (Console.ReadLine ( ));
                    ok = 1;
                }
                catch (FormatException) {
                    Console.WriteLine ("--------------\nWrong value!\n--------------");
                }
            } 

            //5x+8y=0
            //7x+10y=0
            while (ok != 0) {
                x++;
                tmp = a1 * x + b1;
                y = tmp;
                tmp = a1 * x + b1 * y;
            }







        }
    }
}
