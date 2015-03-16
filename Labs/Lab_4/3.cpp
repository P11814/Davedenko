// http://ru.onlinemschool.com/math/assistance/equation/gaus/
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
    class Program {
        static void Main ( string [] args ) {
            double A1=4, B1=12, C=8;
            double A2=16, B2=8, D=25;
            double x=0, y=0;
            //1
            A1/=A1;
            B1/=A1;
            C/=A1;
            //2
            B2-=B1*A2;
            D-=C*A2;
            A2-=A1*A2;
            //3
            A2/=-2;
            B2/=-2;
            D/=-2;
            //4
            A1-=A2*2;
            B1-=B2*2;
            C-=D*2;
            // solution 
            x=C;
            y=D;
            Console.WriteLine ("  x={0}\n  y={1}\n", x, y);
                
        }
    }
}
