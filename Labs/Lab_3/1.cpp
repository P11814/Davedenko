using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
// Регулярки

namespace Laba_3 {
    class Program {
        static void Main (string[] args) {

            /* 1.	Необходимо обернуть повторяющиеся слово в <strong> элемент
             * This test test is is  -->  This test<strong> test</strong> is<strong> is</strong>
             */
            Console.WriteLine ("Введите строку:");
            string str="This test test is is";
            string result=Regex.Replace (str, @"(\b(\w+?)\s)(\2)\b", "${1}<strong>${3}</strong>");
            Console.WriteLine (result);
        }
    }
}
