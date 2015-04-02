using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exam {
    public enum Races {                    //- раса (человек, гном, эльф, орк, дракон, …) (*);
        Human,
        Gnome,
        Elf,
        Orc,
        Dragon
    };
    public enum Condition {                      //- состояние (нормальное, ослаблен, болен, отравлен, парализован, мертв);
        Normal,
        Weak,
        Seak,
        Poisoned,
        Paralised,
        Dead
    };
    public enum Sex {                             //- состояние (нормальное, ослаблен, болен, отравлен, парализован, мертв);
        Male,
        Female,

    };
    public class Hero {

        public readonly Guid id = new Guid ("00000000000000000000000000000000");  //- уникальный числовой идентификатор(*);

        public string name="JohnDoe";                                 //- имя персонажа;
        public string NAME {
            get {
                return name;
            }
        }



        readonly Races condition;                           //- состояние     
        public Races CONDITION {
            get {
                return condition;
            }
        }



        readonly Races race;
        public Races RACE {
            get {
                return race;
            }
        }

         readonly Sex sex;                               //- пол (*);
        public Sex SEX {
            get {
                return sex;
            }
        }

        int age = 0;                                     //- возраст;
        public int AGE {
            get {
                return age;
            }
            set {
                age = value;
            }
        }

        bool move = true;                                   //- возможность двигаться;

        bool talk = true;                                   //- возможность разговаривать;


        int health = 0;                                     //- текущее значение здоровья персонажа (неотрицательная величина);
        public int HEALTH {
            get {
                return health;
            }
            set {
                health = value;
            }
        }

        const int maxHealth = 1000;                           //- максимальное значение для здоровья персонажа;
        public int MAXHEALTH {
            get {
                return maxHealth;
            }
        }

        int experience = 0;                              //- количество опыта, набранное персонажем.
        public int EXPERIENCE {
            get {
                return experience;
            }
            set {
                experience = value;
            }
        }

        /*Звездочкой помечены поля, не изменяющиеся после создания персонажа.
        Значения полей «состояние», «раса» и «пол» определить через enum.*/


        //- конструктор, задающий значения неизменяемых полей и обеспечивающий уникальность идентификатора для нового объекта;
        public Hero(Races race, Sex sex, int health, int experience, string name) {

            this.id = Guid.NewGuid ( );
            this.race = race;
            this.sex = sex;
            this.health = health;
            this.experience = experience;
            this.name = name;
        }


        //- сравнение персонажей по опыту и проценту здоровья (отношению текущего здоровья персонажа к максимальному количеству здоровья);
        public static bool operator >(Hero hero1, Hero hero2) {

            if (( hero1.experience > hero2.experience ) && ( ( (hero1.health/100)*hero1.MAXHEALTH > (hero2.health/100)*hero2.MAXHEALTH ) )) {
                //Console.WriteLine ("\n{0} stronger than {1}", hero1.name, hero2.name);
                return true;
            }
            else {
                return false;
            }

            
        }
        public static bool operator <(Hero hero1, Hero hero2) {

            if (( hero1.experience < hero2.experience ) && ( ( (hero1.health/100)*hero1.MAXHEALTH < (hero2.health/100)*hero2.MAXHEALTH ) )) {
                //Console.WriteLine ("\n{0} stronger than {1}", hero1.name, hero2.name);
                return true;
            }
            else {
                return false;
            }
        }




    }






    class Program {
        static void Main(string [] args) {

            Hero hero1 = new Hero (Races.Dragon, Sex.Female, 100, 120, "Smaug");
            Hero hero2 = new Hero (Races.Gnome, Sex.Female, 80, 70, "Gimli");
            Console.WriteLine ("Hero1 id = {0}\nHero2 id = {1}", hero1.id, hero2.id);
            Console.WriteLine ("hero1 > hero2  {0}",hero1 > hero2);
            Console.WriteLine ("hero1 < hero2  {0}",hero1 < hero2);







        }
    }
}
