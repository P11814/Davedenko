using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*
3.	Разработать метод для решения системы 2 линейных уравнений:
A1*x + B1*y = 0 (C1)
A2*x + B2*y = 0 (C2)
Метод с помощью выходных параметров должен возвращать найденной решение или генерирует исключение ArgumentOutOfRangeException,
если решение не существует. 
*/

namespace Laba_4_3 {
    public class LineFunction {
        public double A1=0, B1=0, C=0;
        public double A2=0, B2=0, D=0;

        double x=0, y=0;

        public void solution ( ) {

            //1
            B1/=A1;
            C/=A1;
            A1/=A1;

            //2
            B2-=B1*A2;
            D-=C*A2;
            A2-=A1*A2;

            //3
            D/=B2;
            B2/=B2;

            //4
            C-=D*B1;
            B1-=B2*B1;

            // solution 
            x=C;
            y=D;
             
            
        }


        public double X {
            get {
                return x;
            }
        }
        public double Y {
            get {
                return y;
            }
        }
    



    }// end class LineFunction


    class Program {
        static void Main ( string [] args ) {
            LineFunction func=new LineFunction ();


            Console.WriteLine (@"Введите значения для двух линейных уравнений:
A1*x + B1*y = C
A2*x + B2*y = D"+"\n");

            Console.Write ("A1 = ");
            while (func.A1 == 0) {
                try { // код на введение коэффициентов повторяется 6 раз. такие вещи надо помещать в отдельный 
                // закрытый метод, чтобы не копировать лишний раз код. мы ж не в Индии
                    func.A1 = int.Parse (Console.ReadLine ());
                } catch (FormatException) {
                    Console.WriteLine ("Введите число");
                }
            }

            Console.Write ("B1 = ");
            while (func.B1 == 0) {
                try {
                    func.B1 = int.Parse (Console.ReadLine ());
                } catch (FormatException) {
                    Console.WriteLine ("Введите число");
                }
            }

            Console.Write ("C  = ");
            while (func.C == 0) {
                try {
                    func.C = int.Parse (Console.ReadLine ());
                } catch (FormatException) {
                    Console.WriteLine ("Введите число");
                }
            }

            Console.Write ("A2 = ");
            while (func.A2 == 0) {
                try {
                    func.A2 = int.Parse (Console.ReadLine ());
                } catch (FormatException) {
                    Console.WriteLine ("Введите число");
                }
            }

            Console.Write ("B2 = ");
            while (func.B2 == 0) {
                try {
                    func.B2 = int.Parse (Console.ReadLine ());
                } catch (FormatException) {
                    Console.WriteLine ("Введите число");
                }
            }

            Console.Write ("D  = ");
            while (func.D == 0) {
                try {
                    func.D = int.Parse (Console.ReadLine ());
                } catch (FormatException) {
                    Console.WriteLine ("Введите число");
                }
            }
            func.solution ();
            Console.WriteLine ("\nРешение:\n--------");
            Console.WriteLine ("x={0}  y={1}", func.X, func.Y);

        }
    }
}
