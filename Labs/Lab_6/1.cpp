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


namespace Laba_6
{




    class Product
    {
        string name;
        int num;
        int price;
        int numPlaceOfProd;

        public Product(string nam, int num, int price)
        {
            this.name = nam;
            this.num = num;
            this.price = price;
        }







        public string NAME
        {
            set
            {
                if (value.Length > 0)
                    name = value;
                else
                    Console.WriteLine("Wrong value");
            }
            get
            {
                return name;
            }
        }


        public int NUM
        {
            set
            {
                if (value > 0)
                    num = value;
                else
                    Console.WriteLine("Wrong value");
            }
            get
            {
                return num;
            }
        }


        public int PRICE
        {
            set
            {
                if (value > 0)
                    price = value;
                else
                    Console.WriteLine("Wrong value");
            }
            get
            {
                return price;
            }
        }
        public int NUMPLACEOFPRODUCT
        {
            set
            {
                if (value > 0)
                    numPlaceOfProd = value;
                else
                    Console.WriteLine("Wrong value");
            }
            get
            {
                return numPlaceOfProd;
            }
        }

    }// end class Product






    public class Storage
    {
        static int numOfProduct = 0;// count of products
        static int sizeOfStorage = 0;

        Product[] product;// array of products
        public Storage(int num)
        {
            sizeOfStorage = num;
            product = new Product[num];

        }// end constructor Storage

        public void sortByPrice()
        {
            int[] tmp = new int[numOfProduct];
            for (int i = 0; i < numOfProduct; i++)
            {
                tmp[i] = product[i].PRICE;
            }
            Array.Sort(tmp);
            Console.WriteLine("Sorted by price\n----------------------");
            Console.WriteLine("Name:     Number:    Price:\n");
            for (int i = 0; i < numOfProduct; i++)
            {
                for (int j = 0; j < numOfProduct; j++)
                {
                    if (tmp[i] == product[j].PRICE)
                    {
                        Console.WriteLine("{0}      {1} шт.     {2}  p.", product[j].NAME, product[j].NUM, product[j].PRICE);
                    }
                }
            }
            Console.WriteLine("\n");

        }//end sortByPrice

        public void sortByNumber()
        {
            int[] tmp = new int[numOfProduct];
            for (int i = 0; i < numOfProduct; i++)
            {
                tmp[i] = product[i].NUM;
            }
            Array.Sort(tmp);
            Console.WriteLine("Sorted by number\n----------------------");
            Console.WriteLine("Name:     Number:    Price:\n");
            for (int i = 0; i < numOfProduct; i++)
            {
                for (int j = 0; j < numOfProduct; j++)
                {
                    if (tmp[i] == product[j].NUM)
                    {
                        Console.WriteLine("{0}      {1} шт.     {2}  p.", product[j].NAME, product[j].NUM, product[j].PRICE);
                    }
                }
            }
            Console.WriteLine("\n");
        }  //end sortByNumber


        public void sortByName()
        {
            string[] tmp = new string[numOfProduct];
            for (int i = 0; i < numOfProduct; i++)
            {
                tmp[i] = product[i].NAME;
            }
            Array.Sort(tmp);
            Console.WriteLine("Sorted by name\n----------------------");
            Console.WriteLine("Name:     Number:    Price:\n");
            for (int i = 0; i < numOfProduct; i++)
            {
                for (int j = 0; j < numOfProduct; j++)
                {
                    if (tmp[i] == product[j].NAME)
                    {
                        Console.WriteLine("{0}      {1} шт.     {2}  p.", product[j].NAME, product[j].NUM, product[j].PRICE);
                    }
                }
            }
            Console.WriteLine("\n");
        }  //end sortByName



        public void addProduct(string nam, int num, int price)
        {
            if (numOfProduct != sizeOfStorage)
            {
                Console.WriteLine("aaaaaaaaaaaaaa   {0}    aaaaaaaaaaaaaaaa");
                product[numOfProduct] = new Product(nam, num, price);
                numOfProduct++;
                product[numOfProduct - 1].NUMPLACEOFPRODUCT = numOfProduct;

            }
            else
            {
                Console.WriteLine("Склад заполнен");
            }
        }// end addProduct


        public void findProductByNumber(int number)
        {

            Console.WriteLine("Name:     Number:    Price:");
            for (int i = 0; i < numOfProduct; i++)
            {
                if (product[i].NUMPLACEOFPRODUCT == number)
                {
                    Console.WriteLine(@"
{0}      {1} шт.     {2}  p.
---------------
               ", product[i].NAME, product[i].NUM, product[i].PRICE);
                }
            }
            if (product[numOfProduct - 1].NUMPLACEOFPRODUCT < number)
            {
                Console.WriteLine("-------------------------------------\nThere is no product with this number.\n-------------------------------------\n");
            }
        } // end findProductByNumber


        public void findProdByName(string nam)
        {
            int tmp = 0;

            for (int i = 0; i < numOfProduct; i++)
            {
                if (product[i].NAME == nam)
                {
                    Console.WriteLine("Name:     Number:    Price:");
                    Console.WriteLine(@"
{0}      {1} шт.     {2}  p.
------------------------------
               ", product[i].NAME, product[i].NUM, product[i].PRICE);

                }
                if (product[i].NAME != nam)
                {
                    tmp++;
                }
            }
            if (tmp == numOfProduct)
            {
                Console.WriteLine("-------------------------------------\nThere is no product with this name.\n-------------------------------------\n");
            }
        }// end findProdByName

        public string this[int index]
        {
            

            get
            {
                return product[index-1].NAME;
            }
        }
    }// end class Storage




    class Program
    {
        static void Main(string[] args)
        {

            Storage prod = new Storage(100);
            prod.addProduct("apple", 20, 45);
            prod.addProduct("apple", 212, 34);
            prod.addProduct("bred", 200, 15);
            prod.addProduct("banana", 76, 10);
            prod.addProduct("potato", 235, 12);
            prod.addProduct("cola", 432, 98);
            prod.addProduct("pepsi", 195, 45);
            prod.addProduct("food3", 435, 16);
            prod.addProduct("peach", 498, 65);
            prod.addProduct("food5", 45, 35);
            string str;
            int numsearch = 0;

            Console.Write("Ведите номер товара, который вы хотите найти: ");
            while (numsearch == 0)
            {
                try
                {
                    numsearch = int.Parse(Console.ReadLine());
                }
                catch (FormatException)
                {
                    Console.WriteLine("Введите число");
                }

            }
            prod.findProductByNumber(numsearch);


            Console.Write("Ведите наименование товара, который вы хотите найти: ");
            str = Console.ReadLine();
            prod.findProdByName(str); // получается, если у вас 2 и более продуктов с одинаковым наименованием, то выводится только первый. это не правильно

            prod.sortByPrice(); // сортировки отлично
            prod.sortByNumber();
            prod.sortByName();            
            //а где обращение к продукту по индексу? индексатор надо сделать в классе
            Console.WriteLine(prod[5]);//Вот оно обращение
        }
    }
}
