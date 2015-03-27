using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Laba_2
{



    class Program
    {
        public static void compJagArr()
        {

        }
        static void Main(string[] args)
        {


            //Задание 2. Массивы
            //Напишите программу для вычисления разности двух рваных массивов. 
            //Каждый отсутствующий элемент при необходимости заменить нулем. 

            /// создание и инициалиация рваного массива
            // массивы надо вводить рандомно. рандомно размеры, рандомно значения

            // создание и инициалиация рваного массива
            Random rand = new Random();
            int r;
            //рандомные размеры для первого
            int sizeArr1 = rand.Next(1, 10);
            int[][] arr1 = new int[sizeArr1][];
            //рандомные размеры для второго
            int sizeArr2 = rand.Next(1, 10);
            int[][] arr2 = new int[sizeArr2][];
            //рандомные длины строк для первого
            for (int i = 0; i < sizeArr1; i++)
            {
                r = rand.Next(1, 10);
                arr1[i] = new int[r];
            }
            //рандомные длины строк для второго
            for (int i = 0; i < sizeArr2; i++)
            {
                r = rand.Next(1, 10);
                arr2[i] = new int[r];
            }

            // макс длинна рваного массива
            int maxLengthArray = arr1.Length > arr2.Length ? arr1.Length : arr2.Length;
            // мин длина рваного массива
            int minLengthArray = arr1.Length < arr2.Length ? arr1.Length : arr2.Length;

            //рандомные значения для первого
            for (int i = 0; i < sizeArr1; i++)
            {
                for (int j = 0; j < arr1[i].Length; j++)
                {
                    r = rand.Next(1, 10);
                    arr1[i][j] = r;
                }
            }
            //рандомные значения для второго
            for (int i = 0; i < sizeArr2; i++)
            {
                for (int j = 0; j < arr2[i].Length; j++)
                {
                    r = rand.Next(1, 10);
                    arr2[i][j] = r;
                }
            }
            //вывод первого
            Console.WriteLine("Исходные массивы:\n1.\n-------------------");
            for (int i = 0; i < arr1.Length; i++)
            {
                for (int j = 0; j < arr1[i].Length; j++)
                {

                    Console.Write("{0} ", arr1[i][j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine();
            //вывод второго
            Console.WriteLine("2.\n-------------------");
            for (int i = 0; i < arr2.Length; i++)
            {
                for (int j = 0; j < arr2[i].Length; j++)
                {

                    Console.Write("{0} ", arr2[i][j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine();

            // времменый рванный массив с макс длинной
            int[][] tmpArr = new int[maxLengthArray][];

            int ok=0;

            if (maxLengthArray == arr1.Length)
            {
                for (int i = 0; i < maxLengthArray; i++)
                {
                    tmpArr[i] = new int[arr1[i].Length];
                }
                ok=1;
            }
            else
            {
                for (int i = 0; i < maxLengthArray; i++)
                {
                    tmpArr[i] = new int[arr2[i].Length];
                }
                
            }


            if (ok == 1)
            {
                for (int i = 0; i < minLengthArray; i++)
                {
                    if (tmpArr[i].Length < arr2[i].Length)
                    {
                        tmpArr[i] = new int[arr2[i].Length];

                    }
                }

            }
            else
            {
                for (int i = 0; i < minLengthArray; i++)
                {
                    if (tmpArr[i].Length < arr1[i].Length)
                    {
                        tmpArr[i] = new int[arr1[i].Length];

                    }
                }

            }

            int minLengthString;
            for (int i = 0; i < minLengthArray; i++)
            {
                minLengthString=arr1[i].Length<arr2[i].Length ? arr1[i].Length : arr2[i].Length;
                //Console.WriteLine("min string {0}", minLengthString);
                for (int j = 0; j < minLengthString; j++)
                {
                    tmpArr[i][j] = arr1[i][j]-arr2[i][j];
                }
            }


            Console.WriteLine("Итоговый массив:\n-------------------");
            for (int i = 0; i < tmpArr.Length; i++)
            {
                for (int j = 0; j < tmpArr[i].Length; j++)
                {
                    Console.Write("{0} ", tmpArr[i][j]);
                }
                Console.WriteLine();
            }



        }
    }
}
