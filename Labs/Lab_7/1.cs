using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
 1 Создать абстрактный класс Издание с методами позволяющим вывести на экран информацию об издании,
   а также определить является ли данное издание искомым.
 2 Создать производные классы: 
   Книга (название, фамилия автора, год издания, издательство), 
   Статья (название, фамилия автора, название журнала, его номер и год издания), 
   Электронный ресурс (название, фамилия автора, ссылка, аннотация) со своими методами вывода информации на экран.
 3 Создать каталог (массив) из n изданий, вывести полную информацию из каталога, а также организовать поиск изданий
   по фамилии автора.
*/

namespace Laba_7 {

    class Program {





        public abstract class Publication {
            string authorLastName;
            public string AUTHORLASTN {
                get { return authorLastName; }
                set {
                    if (value!=null) {
                        authorLastName=value;
                    }
                }
            }
            string title;
            public string TITLE {
                get { return title; }
                set {
                    if (value!=null) {
                        title=value;
                    }
                }
            }
        
            public abstract void PublicationInfo ();


        }






        public class Book:Publication {        

            string publ;
            int date;
            public Book (string title, string lastN, string publ, int date) {
                TITLE=title;
                AUTHORLASTN=lastN;
                this.publ=publ;
                this.date=date;

            }
            public override void PublicationInfo () {
                Console.WriteLine (@"Название:      {0}
Автор:         {1}
Издательство:  {2}
Год:           {3}
________________________", TITLE,AUTHORLASTN,publ, date);
            }

        }







        class Article:Publication {
            

            string journalName;
            int journalId;
            int date;
            public Article (string title, string lastN, string journalN, int journalID, int date) {
                TITLE=title;
                AUTHORLASTN=lastN;
                this.journalName=journalN;
                this.journalId=journalID;
                this.date=date;
            }
            public override void PublicationInfo () {
                Console.WriteLine (@"Название:      {0}
Автор:         {1}
Журнал:        {2}
Номер:         {3}
Год:           {3}
________________________", TITLE, AUTHORLASTN,journalName,journalId, date);
            }

        }






        class WebSourse:Publication {
           
            string link;
            string anotation;
            public WebSourse (string title, string lastN, string link, string anot) {
                TITLE=title;
                AUTHORLASTN=lastN;
                this.link=link;
                this.anotation=anot;
            }
            public override void PublicationInfo () {
                Console.WriteLine (@"Название:      {0}
Автор:         {1}
Ссылка:        {2}
Аннотация:     {3}
________________________", TITLE, AUTHORLASTN, link, anotation);
            }

        }






        private static void findByLastName (Publication[] pub, string p) {
            for (int i=0; i<pub.Length; i++) {
                if (pub[i]!=null) {
                    if (pub[i].AUTHORLASTN==p  ) {
                        Console.WriteLine ("{0} публиковался в \"{1}\"", pub[i].AUTHORLASTN,pub[i].TITLE);
                    }
                }
            }
        }





        // Специально не делал ввод с клавиатуры, чтобы проще проверялось
        // Если надо, то я в миг доделаю
        static void Main (string[] args) {

            Publication[] pub=new Publication[1000];

            pub[0]=new Book ("Азбука", "Федоров", "Рассвет", 1917);
            pub[1]=new Article ("Свобода", "Михалок", "Непокоренные", 1, 2015);
            pub[2]=new WebSourse ("Заря", "Федоров", "www.onliner.by", "О белорусских красотах.");

            for (int i=0; i<pub.Length; i++) {
                if (pub[i]!=null) {
                    pub[i].PublicationInfo ();
                }
            }
            Console.WriteLine ("\n\n");

            findByLastName (pub, "Федоров");
            
        }


    }
}
