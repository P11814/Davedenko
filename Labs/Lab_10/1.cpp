using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
/*
 ЛР 10. Работа с файлами и каталогами

Задание 1. Чтение и запись в файл.
Написать приложение, позволяющее:
•	создать новый файл с именем «Day17.txt». В случае наличия файла с таким именем  –  вывести сообщение;
•	открыть и прочесть файл с именем «Day17.txt». В случае отсутствия – вывести сообщение об отсутствии;
•	записать форматированную информацию в файл;
Структура записываемой информации:
Исходные данные: двумерный массив дробных чисел.
                                 двумерный массив  целых чисел.
   – фамилия, имя, отчество, дата рождения
   – с новой строки  количество строк и столбцов массива дробных чисел.
   –  с новой строки  значения элементов двумерного массива (каждая строка массива в новой строке файла). 
   – с новой строки  количество строк и столбцов массива целых чисел.
   – с новой строки  двумерный массив  целых чисел, записанных в одну строку. 
–  с новой строки  текущая дата.
•	прочесть информацию из файла и преобразовать ее в соответствии с исходной структурой.
Реализовать простейшее меню.
*/

namespace Laba_10 {


    class Program {


        public static void createFile (string name) {
            FileStream fout;
            name+=".txt";
            try {
                fout=new FileStream (name, FileMode.CreateNew);
            }
            catch (IOException exc) {
                Console.WriteLine (exc.Message+"Cannot open file.\n");
                return;
            }

            StreamWriter fstr_out=new StreamWriter (fout);
            fout.Close ();

        }

        public static void openFile (string name) {
            FileStream fin;
            
            try {
                fin=new FileStream (name, FileMode.Open);
            }
            catch (FileNotFoundException exc) {
                Console.WriteLine (exc.Message+"Cannot open file.");
                Console.WriteLine ();
                return;
            }
            Console.WriteLine ("Содержимое файла:\n");
            StreamReader fstr_in=new StreamReader (fin);

            while ((name=fstr_in.ReadLine ())!=null) {
                Console.WriteLine (name);
            }
            Console.WriteLine ();
            fstr_in.Close ();

        }

        public static void changeDataFile (string name) {
            name+=".txt";

        }







        static void Main (string[] args) {

            int ok=5;

            while (ok!=0) {

                Console.WriteLine (@"1. Создать файл
2. Открыть и прочесть файл
3. Записать форматированную информацию в файл");
                Console.WriteLine ();
                Console.Write ("Введите число: ");


                try {
                    ok=int.Parse (Console.ReadLine ());
                }
                catch (FormatException) {
                    Console.WriteLine ();                   
                }
                catch (OverflowException) {
                    Console.WriteLine ();
                    Console.WriteLine (@"------------------------
Слишком бльшое значение!
------------------------");
                }



                if (ok<0||ok>3) {
                    Console.WriteLine ();
                }

                switch (ok) {


                    case 1:
                        Console.Write ("Введите имя файла: ");
                        string strTmp1=string.Concat (Console.ReadLine ());
                        Console.WriteLine ();
                        createFile (strTmp1);
                        break;



                    case 2:
                        Console.Write ("Введите имя файла: ");
                        string strTmp2=string.Concat (Console.ReadLine ());
                        Console.WriteLine ();
                        openFile (strTmp2);
                        break;



                    case 3:
                        Console.Write ("Введите имя файла: ");
                        string strTmp3=string.Concat (Console.ReadLine ());
                        Console.WriteLine ();
                        changeDataFile (strTmp3);
                        break;


                    case 0:
                        ok=0;
                        break;


                }
            }








        }
    }
}
