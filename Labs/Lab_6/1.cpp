using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*Создать класс «Товар», содержащий следующие закрытые поля: название товара, количество, стоимость товара в рублях.
 * Обеспечить проверку на правильность ввода данных. Предусмотреть свойства для получения состояния объекта. 
  
 * 
 * Создать класс «Склад», содержащий закрытый массив товаров. Обеспечить: 
• вывод информации о товаре по номеру с помощью индекса; 
• вывод информации о товаре, название которого введено с клавиатуры, если таких товаров нет, выдать соответствующее сообщение; 
• сортировку товаров по наименованию, по количеству и по цене.  

*/

//xcv

namespace Laba_6 {




    class Product {
        string name;
        int num;
        int price;

        public Product(string nam, int num, int price) {
            this.name = nam;
            this.num = num;
            this.price = price;
        }

        public string NAME {
            set {
                if (value.Length > 0)
                    name = value;
                else
                    Console.WriteLine ("Wrong value");
            }
            get {
                return name;
            }
        }


        public int NUM {
            set {
                if (value > 0)
                    num = value;
                else
                    Console.WriteLine ("Wrong value");
            }
            get {
                return num;
            }
        }


        public int PRICE {
            set {
                if (value > 0)
                    price = value;
                else
                    Console.WriteLine ("Wrong value");
            }
            get {
                return price;
            }
        }

    }// end class Product






    public class Storage {
        static int numOfProduct = 0;
        Product [] product;
        public Storage(int num) {
            product = new Product [num];
        }

        public void addProduct(string nam, int num, int price) {

            product [numOfProduct] = new Product (nam, num, price);
            numOfProduct++;
        }

        public void findProdByName(string nam) {

            for (int i = 0 ; i < numOfProduct ; i++) {
                if (product [i].NAME == nam) {
                    Console.WriteLine (@"
Name:   {0}
Number: {1} шт.
Price:  {2}  p.
---------------", product [i].NAME, product [i].NUM, product [i].PRICE);
                } 
            }
            if (product [numOfProduct - 1].NAME != nam) {
                Console.WriteLine ("There is no product with this name.");
            }


        }

    }// end class Storage









    class Program {
        static void Main(string [] args) {

            Storage prod = new Storage (100);
            prod.addProduct ("apple", 20, 45);
            prod.addProduct ("bred", 200, 15);
            prod.addProduct ("banana", 76, 10);
            prod.addProduct ("potato", 235, 25);
            string str;
            int numsearch = 0;
            Console.WriteLine ("Ведите номер товара, котрый вы хотите найти: ");
            while (numsearch == 0) {
                try {
                    numsearch = int.Parse (Console.ReadLine ( ));
                }
                catch (FormatException){
                    Console.WriteLine ("Введите число");
                }

            }
            Console.WriteLine ("Ведите наименование товара, котрый вы хотите найти: ");
            str = Console.ReadLine ( );
            prod.findProdByName (str);

            


        }
    }
}

