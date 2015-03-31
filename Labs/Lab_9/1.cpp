using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    delegate void Delegat();

    class SomeEvent
    {
        public event Delegat MaxValue;
        Random r = new Random();
        public void brosok()
        {
            
            int x = r.Next(1, 7);
            Console.WriteLine("x={0}", x);
            if (x == 6 && MaxValue!=null)
            {
                MaxValue();
            }
    
        }
    }// end SomeEvent

    public class EventElse
    {
        public static void handler()
        {
            Console.WriteLine("Все получилось, 6 ");
        }
    }

    class Program
    {
        
        static void Main(string[] args)
        {
            SomeEvent ev = new SomeEvent();
            ev.MaxValue += new Delegat(EventElse.handler);
            for (int i = 0; i < 10; i++)
            {
                ev.brosok();
            }


        }
    }
} 
