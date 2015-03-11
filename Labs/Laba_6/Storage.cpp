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

        public Product(string nam, int num, int price)
        {
            this.name=nam;
            this.num=num;
            this.price=price;
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

    }






        public class Storage {
            static int count = 0;
            int numberOfProduct;
            Product [] product;


            public Storage(int num) {
                product = new Product [num];
            }

            /*public Storage(string nam,int num,int pric) {
                
            }*/

            public void addProduct(string nam, int num, int price) {
               
                product [count++] = new Product (nam, num, price);
                
            }



            public void  findProduct(string nam) {

               for(int i=0;i<count;i++){

               }


                
            }

        }


    

    




    class Program {
        static void Main(string [] args) {

            Storage prod = new Storage(100); 
            prod.addProduct("Apple",20,45);





        }
    }
}
