using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
Разработать собственный класс для хранения целочисленных коэффициентов А и В линейного уравнения A*X + B*Y = 0.
 * В классе реализовать статический метод Parse, которые принимает строку со значениями коэффициентов,
 * разделенных запятой или пробелом. В случае передачи в метод строки недопустимого формата генерируется исключение FormatException.*/

namespace Laba_4_2 {
    public class LineFunction {
        static int a=0;
        static int b=0;
        static int x=0;
        static int y=0;
       
        public LineFunction ( string str ) {
            Parse(str);
        }
        static void Parse (string str ) {
            try {

                //забиваем слово в массив, если встречается орпеделенный символ
                string [] SplitStr = str.Split (new Char [] { ' ', ',' });
                a=int.Parse (SplitStr [0]);
                b=int.Parse (SplitStr [1]);
                Console.WriteLine ("a-{0} b-{1}", a, b);
            } catch (FormatException) {
                Console.WriteLine ("Wrong value");
            }
        }
        
    }//end class LineFunction


    class Program {
        static void Main ( string [] args ) {
            Console.WriteLine ("Введите значения А и В через запятую или пробел: ");
            string str=Console.ReadLine ();
            LineFunction lineF=new LineFunction (str);
            
        }
    }
}
