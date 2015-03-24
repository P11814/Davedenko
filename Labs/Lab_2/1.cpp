using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Laba_2 {
    class Program {
        static void Main ( string[] args ) {

            /*     Задание 1.
                   Дана строка текста, в которой слова разделены запятыми. Необходимо:
                              - определить количество слов в строке;
                              - определить, сколько слов в строке имеют максимальную длину;
                              - определить, есть ли в данной строке повторяющиеся слова, и вывести их на экран.
            */

            string str = "be,hair,help,maid,because,is,hair,she,is,jealous"; // если добавлю в конце строки слово is, то оно
            // становится повторяющимся, но почему-то не выводит на экран 
            Console.WriteLine ( str );
            Console.WriteLine ( "--------------------------------------------" );
            string[] SplitStr = str.Split ( new Char[] { ' ', ',', '.', ':', '!', '?', '\t' } );//забиваем слово в массив, если встречается орпеделенный символ
            Console.Write ( "Всего {0} слов(а) в строке\n", SplitStr.Length );
            int MaxWordLength = 0;
            foreach ( string s in SplitStr ) {
                if ( s.Length > MaxWordLength ) { MaxWordLength = s.Length; }
            }
            int countMax = 0;
            foreach ( string s in SplitStr ) {
                if ( s.Length == MaxWordLength ) { countMax++; }
            }
            Console.Write ( "Всего {0} слов(а) имеют максимальную длинну\n", countMax );

            Console.Write ( "Повторяющиеся слова:\n" );
            int StrLength = SplitStr.Length;
            int result = 0;
            countMax = 0;
            for ( int i = 0; i < SplitStr.Length; i++ ) {
                for ( int j = 0; j < SplitStr.Length; j++ ) {
                    result = String.CompareOrdinal ( SplitStr[i], SplitStr[j] );
                    if ( result == 0 ) {
                        countMax++;
                        if ( countMax == 2 ) {
                            Console.WriteLine ( "{0}", SplitStr[i] );
                        }
                    }
                } //countMax = 0;
            } 

        }
    }
}
