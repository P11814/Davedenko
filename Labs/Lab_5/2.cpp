using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _5._2 {

    class Fraction {
        public double n;
        public double d;

        public Fraction ( ) {
            n = 0;
            d = 0;
        }
        public Fraction ( int num, int den ) {
            n = num;
            d = den;
        }
        public static Fraction operator * ( Fraction f, int x ) {
            //создаем времменую дробь         
            Fraction fract = new Fraction ( );
            //перемножаем дроби и записываем во временную
            fract.n = f.n * x;
            fract.d = f.d;
            // ищем наибольшее  и наименьшее значение дроби
            double max = ( fract.n > fract.d ) ? fract.n : fract.d;
            double min = ( fract.n < fract.d ) ? fract.n : fract.d;
            // ищем НОК
            double NOK =0 ;
            do {
                NOK+=max;
            } while ( NOK % min!= 0 );
            // ищем НОД
            double NOD = ( min * max ) / NOK;
            // сокращаем дробь
            fract.n /= NOD;
            fract.d /=NOD ;
            return fract;
        }
        public static Fraction operator * ( int x, Fraction f ) {
            //создаем времменую дробь         
            Fraction fract = new Fraction ( );
            //перемножаем дроби и записываем во временную
            fract.n = f.n * x;
            fract.d = f.d;
            // ищем наибольшее  и наименьшее значение дроби
            double max = ( fract.n > fract.d ) ? fract.n : fract.d;
            double min = ( fract.n < fract.d ) ? fract.n : fract.d;
            // ищем НОК
            double NOK = 0;
            do {
                NOK += max;
            } while ( NOK % min != 0 );
            // ищем НОД
            double NOD = ( min * max ) / NOK;
            // сокращаем дробь
            fract.n /= NOD;
            fract.d /= NOD;
            return fract;
        }


        public static Fraction operator + ( Fraction f, double x ) {
            Fraction fract = new Fraction ( );
            double b = 0;
            double count = 0;
            //проверяем есть ли значения после запятой
            int a = (int )x;
            b = x - a;
            //проверяем сколько значений после запятой
            if ( b != 0 ) {
                do {
                    count++;
                    b *= 10;
                    a = ( int ) b;
                    b = b - a;
                } while ( b != 0 );
            }
            //Console.WriteLine ( "test count={0}",count );
            //записываем значения в дробь
            fract.n = x * ( 10 * count );
            fract.d = Math.Pow ( 10, count );
            //Console.WriteLine ( "num={0} den={1} ", fract.numerator, fract.denominator );
            //ищем мин и макс для НОК 
            double max =  fract.d > fract.n  ? fract.d : fract.n;
            double min = fract.d < fract.n ? fract.d : fract.n;
            //Console.WriteLine ( "max={0} min={1} ", max,min );
            //ищем НОК
            double NOK = 0; // что ж вы делаете то. одинаковый подсчет НОК 3 раза в разных перегрузках. 
            // хорошие программисты повторяющийся код помещают в функцию и в 3-ех перегрузках просто вызывают эту функцию!!!
        
            do {
                NOK += max;
            } while ( NOK % min != 0 );
            //Console.WriteLine ( "NOK={0} ",NOK );
            // ищем НОД
            double NOD = ( min * max ) / NOK;
            //Console.WriteLine ( "NOD={0} ", NOD );
            // сокращаем дробь
            fract.n /= NOD;
            fract.d /= NOD;
            //Console.WriteLine ( "fraction {0}/{1} ",fract.numerator,fract.denominator  );
            //плюсуем дроби
            //ищем мин и макс для НОК
            max = f.d > fract.d ? f.d : fract.d;
            min = f.d < fract.d ? f.d : fract.d;
            //Console.WriteLine ( "max={0} min={1} ", max, min );
            //ищем НОК
            NOK = 0;
            do {
                NOK += max;
            } while ( NOK % min != 0 );
            //Console.WriteLine ( "NOK={0} ", NOK );
            // ищем НОД
            NOD = ( min * max ) / NOK;
            //Console.WriteLine ( "NOD={0} ", NOD );
            //записываем значения в дробь
            fract.n = ( ( NOK / fract.d ) * fract.n ) + ( ( NOK / f.d ) * f.n );
            fract.d = NOK;
            return fract;
        }


    }



    class Program {
        static void Main ( string[] args ) {
            Fraction f = new Fraction ( 3, 4 );
            int a = 10;            
            Fraction f1 = f * a;
            Console.WriteLine ( "f1={0}/{1} ", f1.n, f1.d );
            Fraction f2 = a * f;
            Console.WriteLine ( "f2={0}/{1} ", f2.n, f2.d );
            double d=1.5;
            Fraction f3 = f + d;
            Console.WriteLine ( "f3={0}/{1} ", f3.n, f3.d );

        }
    
    
    
    
    
    }
}
