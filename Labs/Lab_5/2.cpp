using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _5._2 {

    class Fraction {
        public double numerator;
        public double denominator;

        public Fraction ( ) {
            numerator = 0;
            denominator = 0;
        }
        public Fraction ( int num, int den ) {
            numerator = num;
            denominator = den;
        }
        public static Fraction operator * ( Fraction f, int x ) {
            Fraction fract = new Fraction ( );
            fract.numerator = f.numerator * x;
            fract.denominator = f.denominator;
            return fract;
        }
        public static Fraction operator * ( int x, Fraction f ) {
            Fraction fract = new Fraction ( );
            fract.numerator = f.numerator * x;
            fract.denominator = f.denominator;
            return fract;
        }

        public static Fraction operator + ( Fraction f, double x ) {
            Fraction fract = new Fraction ( );
            double b = 0;
            double count = 0;
            int a = 0;

            do {
                b *= 10;
                a = ( int ) x;
                b = x - a;
                count++;
            } while ( b == 0 );

            fract.numerator = x * ( 10 * count );//15
            fract.denominator = Math.Pow ( 10, count );//10
            double max = ( fract.denominator > f.denominator ) ? fract.denominator : f.denominator;
            double min = ( fract.denominator < f.denominator ) ? fract.denominator : f.denominator;
            b = max;
 
            do {
                count = max % min;
                max += b;
            } while ( count == 0 );

            fract.numerator = ( ( max / fract.denominator ) * fract.numerator ) + ( ( max / f.denominator ) * f.numerator );
            fract.denominator = max;
            return fract;
        }


    }
 


    class Program {
        static void Main ( string[] args ) {
            Fraction f = new Fraction ( 3, 6 );//
            int a = 10;
            double d = 1.5;
            Fraction f1 = f * a;
            Console.WriteLine ( "f1={0}/{1} ", f1.numerator, f1.denominator );
            Fraction f2 = a * f;
            Console.WriteLine ( "f2={0}/{1} ", f2.numerator, f2.denominator );
            Fraction f3 = f + d;
            Console.WriteLine ( "f3={0}/{1} ", f3.numerator, f3.denominator );



        }
    }
}
