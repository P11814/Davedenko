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


            int DArrHeight, DArrWidth, tmp;
            int IArrHeight, IArrWidth;
            string tmpStr;

            Console.Write ("Введите свое имя: ");
            tmpStr=Console.ReadLine ();
            Console.Write ("Введите свою фамилию: ");
            tmpStr+=" "+Console.ReadLine ();
            Console.Write ("Введите своё отчество: ");
            tmpStr+=" "+Console.ReadLine ();


            Console.WriteLine ("\nВведите свою дату рождения");
            Console.Write ("Число: ");
            while (true) {
                while (!int.TryParse (Console.ReadLine (), out tmp)) { Console.Write ("Введите число ! "); }
                if (tmp>0&&tmp<32) {
                    break;
                }
                Console.Write ("Введите число ! ");
            }
            tmpStr+=" "+tmp;
            //tmp=0;
            Console.Write ("Месяц: ");
            while (true) {
                while (!int.TryParse (Console.ReadLine (), out tmp)) { Console.Write ("Введите число ! "); }
                if (tmp>0&&tmp<13) {
                    break;
                }
                Console.Write ("Введите число ! ");
            }
            tmpStr+=" "+tmp;
            //tmp=0;
            Console.Write ("Год: ");
            while (true) {
                while (!int.TryParse (Console.ReadLine (), out tmp)) { Console.Write ("Введите число ! "); }
                if (tmp>1900&&tmp<2016) {
                    break;
                }
                Console.Write ("Введите число ! ");
            }
            tmpStr+=" "+tmp+"\r\n"; // add newline ;


            Console.Write ("\nВведите размер двумерного массива дробных чисел: ");
            while (!int.TryParse (Console.ReadLine (), out DArrHeight)) { Console.WriteLine ("Введите число !"); }
            tmpStr+=DArrHeight;
            Console.Write ("Введите длину строки двумерного массива дробных чисел: ");
            while (!int.TryParse (Console.ReadLine (), out DArrWidth)) { Console.WriteLine ("Введите число !"); }
            tmpStr+=" "+DArrWidth+"\r\n";

            double DTmp;
            double[,] DArr=new double[DArrHeight, DArrWidth];

            for (int i=0; i<DArrHeight; i++) {
                for (int j=0; j<DArrWidth; j++) {
                    Console.Write ("Введите значение : ");
                    while (!double.TryParse (Console.ReadLine (), out DTmp)) { Console.Write ("Введите число ! - "); }
                    DArr[i, j]=DTmp;
                    tmpStr+=DArr[i, j]+" ";
                }
                tmpStr+="\r\n";
            }


            Console.Write ("\nВведите размер двумерного массива целых чисел: ");
            while (!int.TryParse (Console.ReadLine (), out IArrHeight)) { Console.WriteLine ("Введите число !"); }
            tmpStr+=IArrHeight;
            Console.Write ("Введите длину строки двумерного массива целых чисел: ");
            while (!int.TryParse (Console.ReadLine (), out IArrWidth)) { Console.WriteLine ("Введите число !"); }
            tmpStr+=" "+IArrWidth+"\r\n";

            int[,] IArr=new int[IArrHeight,IArrWidth];

            for (int i=0; i<IArrHeight; i++) {
                for (int j=0; j<IArrWidth; j++) {
                    Console.Write ("Введите значение : ");
                    while (!int.TryParse (Console.ReadLine (), out tmp)) { Console.Write ("Введите число ! - "); }
                    IArr[i, j]=tmp;
                    tmpStr+=IArr[i, j]+" ";
                }
                
            }
            tmpStr+="\r\n";




            int ok=0;
            while (ok==0) {

                string tmpDate=null;
                Console.WriteLine ("\nВведите текущую дату");
                Console.Write ("Число: ");
                while (true) {
                    while (!int.TryParse (Console.ReadLine (), out tmp)) { Console.Write ("Введите число ! "); }
                    if (tmp>0&&tmp<32) {
                        break;
                    }
                    Console.Write ("Введите число ! ");
                }
                if (tmp<10) {
                    tmpDate+="0"+tmp;
                }
                else {
                    tmpDate+=tmp;
                }
                
                //tmp=0;
                Console.Write ("Месяц: ");
                while (true) {
                    while (!int.TryParse (Console.ReadLine (), out tmp)) { Console.Write ("Введите число ! "); }
                    if (tmp>0&&tmp<13) {
                        break;
                    }
                    Console.Write ("Введите число ! ");
                }
                if (tmp<10) {
                    tmpDate+=".0"+tmp;
                }
                else {
                    tmpDate+="."+tmp;
                }
                
                //tmp=0;
                Console.Write ("Год: ");
                while (true) {
                    while (!int.TryParse (Console.ReadLine (), out tmp)) { Console.Write ("Введите число ! "); }
                    if (tmp>1900&&tmp<2016) {
                        break;
                    }
                    Console.Write ("Введите число ! ");
                }
                tmpDate+="."+tmp;

                DateTime thisDay=DateTime.Today;

                if (tmpDate==thisDay.ToString("d")) {
                    tmpStr+=tmpDate;
                    ok=1;
                }

            }



            Console.WriteLine ();

            try {
                fstr_out.Write (tmpStr);
            }
            catch (IOException exc) {
                Console.WriteLine (exc.Message+"File Error");
                return;
            }

            fstr_out.Close ();

        }









        public static void openFile (string name) {
            FileStream fin;
            name+=".txt";
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

            



            int ok=-1;

            while (ok!=0) {

                Console.WriteLine (@"1. Создать файл
2. Открыть и прочесть файл
3. Записать форматированную информацию в файл
0. Выход");
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
