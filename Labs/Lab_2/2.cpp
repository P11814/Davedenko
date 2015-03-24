using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Laba_2 {



    class Program {
        public static void compJagArr ( ) {

        }
        static void Main ( string [] args ) {


            //Задание 2. Массивы
            //Напишите программу для вычисления разности двух рваных массивов. 
            //Каждый отсутствующий элемент при необходимости заменить нулем. 

            /// создание и инициалиация рваного массива
            // массивы надо вводить рандомно. рандомно размеры, рандомно значения
            int [] [] arr1=new int [3] [];
            arr1 [0]=new int [3] { 1, 2, 3 };
            arr1 [1]=new int [1] { 1 };
            arr1 [2]=new int [5] { 1, 2, 3, 4, 5 };
            // создание и инициалиация рваного массива
            int [] [] arr2=new int [4] [];
            arr2 [0]=new int [2] { 1, 2 };
            arr2 [1]=new int [4] { 1, 2, 3, 4 };
            arr2 [2]=new int [6] { 1, 2, 3, 4, 5, 6 };
            arr2 [3]=new int [3] { 1, 2, 3};

            // макс длинна рваного массива
            int maxLengthArray=arr1.Length>arr2.Length?arr1.Length:arr2.Length;
            // мин длина рваного массива
            int minLengthArray=arr1.Length<arr2.Length?arr1.Length:arr2.Length;    
            // времменый рванный массив с макс длинной
            int [] [] tmpArr=new int [maxLengthArray] [];


            // цикл на размер меньшего массива, чтобы не выйти за границу дозволенного
            for (int i=0; i<minLengthArray; i++) {
                //если строка превого массива больше второго
                if (arr1 [i].Length>arr2 [i].Length) {
                   
                    tmpArr [i]=new int [arr1 [i].Length];

                    for (int j=0; j<arr2 [i].Length; j++) {
                        tmpArr [i] [j]=arr2 [i] [j];
                    }
                    arr2 [i]=new int [arr1 [i].Length];

                    for (int j=0; j<arr2 [i].Length; j++) {
                        arr2 [i] [j]=tmpArr [i] [j];
                        
                    }  
                }//end if


                //если строка второго массива больше первого
                if (arr2 [i].Length>arr1 [i].Length) {
                    
                    tmpArr [i]=new int [arr2 [i].Length];

                    for (int j=0; j<arr1 [i].Length; j++) {
                        tmpArr [i] [j]=arr1 [i] [j];
                    }

                    arr1 [i]=new int [arr2 [i].Length];
                    
                    for (int j=0; j<arr2 [i].Length; j++) {
                        arr1 [i] [j]=tmpArr [i] [j];
                    }
                

                }//end if
                
            }//end for


// и почему выводятся 2 массива? нужен один массив, содержащий разность первых
            for (int i=0; i<arr1.Length; i++) {
                for (int j=0; j<arr1 [i].Length; j++) {
                    Console.Write ("{0} ", arr1 [i] [j]);
                }
                Console.WriteLine ();
            }
            Console.WriteLine ();

             for (int i=0; i<arr2.Length; i++) {
                 for (int j=0; j<arr2 [i].Length; j++) {
                     Console.Write ("{0} ",arr2 [i] [j]);
                 }
                 Console.WriteLine ();
             }


        }
    }
}
