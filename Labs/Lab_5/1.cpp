using System; 
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/* 
Реализовать класс для комплексного числа.Выполнть перегрузку всех необходимых операторов
 * для успешной компиляции следующего фрагментного кода:
 * Complex z=new Complex (1, 1);
   Complex z1;
   z1=z-(z*z*z-1)/(3*z*z);
   Console.WriteLine ("z1 = {0}", z1); 
 */
namespace Laba_5_1 {
    class Program {
        class Complex {
            int x=0;
            int y=0;

            Complex ( ) {     }

            public Complex ( int x, int y ) {
                this.x=x;
                this.y=y;
            }
            public static Complex operator - ( Complex x, Complex y ) {
                Complex tmp = new Complex ();
                tmp.x = x.x - y.x;
                tmp.y = x.y - y.y;
                return tmp;
            }

            public static Complex operator - ( Complex comp, int x ) {
                Complex tmp = new Complex ();
                tmp.x = comp.x - x;
                tmp.y = comp.y - x;
                return tmp;
            }

            public static Complex operator * ( Complex x, Complex y ) {
                Complex tmp = new Complex ();
                tmp.x = x.x * y.x;
                tmp.y = x.y * y.y;
                return tmp;
            }

            public static Complex operator * ( int x, Complex comp ) {
                Complex tmp = new Complex ();
                tmp.x = x * comp.x;
                tmp.y = x * comp.y;
                return tmp;
            }
            public static Complex operator / ( Complex comp1, Complex comp2 ) {
                Complex tmp = new Complex ();
                tmp.x = comp1.x / comp2.x;
                tmp.y = comp1.y / comp2.y;
                return tmp;
            }

            public override string ToString ( ) {
                string x = this.x.ToString ();
                string y = this.y.ToString ();
                return   "("+ x + ", i" + y + ")";
            }

        }   //end class Complex
        static void Main ( string [] args ) {
            Complex z=new Complex (1, 1);
            Complex z1;
            z1=z-(z*z*z-1)/(3*z*z);
            Console.WriteLine ("z1 = {0}", z1);

        }
    }
}
