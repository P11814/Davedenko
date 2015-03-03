using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
��_4. ������, ����. ��������, ������������ ����
1.	��������� �����, ����������� �������� � ������������� � ��� ��������� ��������������: �������, ���, ��������, ������ ,
 * �������, ������ ������ (������) �� ����������������, ����������������� �  �������. �������� ������ �� ������ � �������������� �������:
 * ����������� ���������/��������� ������, ��������� �������� ����� �� ��������� ��������, ���������� ������ � ��������.
2.	����������� ����������� ����� ��� �������� ������������� ������������� � � � ��������� ��������� A*X + B*Y = 0. � ������ �����������
 * ����������� ����� Parse, ������� ��������� ������ �� ���������� �������������, ����������� ������� ��� ��������. � ������ �������� � �����
 * ������ ������������� ������� ������������ ���������� FormatException.
3.	����������� ����� ��� ������� ������� 2 �������� ���������:
A1*x + B1*y = 0
A2*x + B2*y = 0
����� � ������� �������� ���������� ������ ���������� ��������� ������� ��� ���������� ���������� ArgumentOutOfRangeException, ���� ������� �� ����������. 
4.	������������ ���������� �7 ����� �����, ��� ������ ���� ����� ������������ ��������� �������. �������� �������������� �����, ���������� ����� �����.
 * ������������ ���������� �� ������ ������� � � ������� ������������ ���� ���������� ����������� �������������� �������. 
5.	����������� ����������, � ������� �� ������������ ��������� ���� ������ �� ������ �����. ������ ������ �� ������������ ������������� ����,
 * � ����� � ������� � ������ ������������.
 * */
namespace ClassWork {
    //---------------------------------------
    class Student {
        string surname;
        string name;
        string fathersname;
        int group;
        int age;
        int[][] ArrRating = new int[3][];


        //�����������
        public Student ( string surname_, string name_, string fathersname_, int age_, int group_ ) {
            surname = surname_;
            name = name_;
            fathersname = fathersname_;
            age = age_;
            group = group_;
            ArrRating[0] = new int[1];
            ArrRating[1] = new int[1];
            ArrRating[2] = new int[1];
        }


        // ���������� � ��������
        public void StudentList ( ) {
            Console.WriteLine ( "{0} {1} {2}\n�������-{3}\n������-{4}\n", surname, name, fathersname, age, group );
        }
        
        // ���� ������
        public void GetRate ( ) {
            Console.WriteLine ( "�������� �������: \n1.����������������\n2.�����������������\n3.������\n" );
            int subject = int.Parse ( Console.ReadLine ( ) );
            Console.WriteLine ( "��������� ������:" );
            int mark = int.Parse ( Console.ReadLine ( ) );
            int StrLenght = ArrRating[subject - 1].Length;

            int[] marks = new int[StrLenght + 1];

            for ( int i = 0; i < StrLenght; ++i ) {
                marks[i] = ArrRating[subject - 1][i];
            }
            marks[StrLenght] = mark;

            ArrRating[subject - 1] = new int[StrLenght + 1];

            for ( int i = 0; i < StrLenght + 1; ++i ) {
                ArrRating[subject - 1][i] = marks[i];
            }
        }


        // ������� ������
        public void MiddleMark ( ) {
            Console.WriteLine ( "�������� �������: \n1.����������������\n2.�����������������\n3.������\n" );
            int subject = int.Parse ( Console.ReadLine ( ) );
            int StrLenght = ArrRating[subject - 1].Length;
            int sum = 0, count = 0;
            for ( int i = 0; i < StrLenght; ++i ) {
                sum += ArrRating[subject - 1][i];
                count++;
            }
            count--;
            Console.WriteLine ( "������� ������ �� ������� - {0}\n\n", sum / count );

        }


        // �������� ������
        public void ShowMarks ( ) {
            Console.WriteLine ( "�������� �������: \n1.����������������\n2.�����������������\n3.������\n" );
            int subject = int.Parse ( Console.ReadLine ( ) );
            int x = ArrRating[subject - 1].Length;
            if ( x == 1 ) {
                Console.WriteLine ( "��� ������\n" );
            } else {
                for ( int i = 1; i < ArrRating[subject - 1].Length; i++ ) {
                    Console.Write ( "{0} ", ArrRating[subject - 1][i], x );
                }
                Console.WriteLine ( );
            }
        }
   
    }// end class Student
    



    class Program {
        static void Main ( string[] args ) {
            int value = 1;

            Student student1 = new Student ( "Gates", "Bill", "Adamovich", 25, 118 );

            while ( value != 0 ) {

                Console.WriteLine ( "1. ���������� � ��������\n2. ��������� ������\n3. ����������� ������\n4. ������� ������\n0. �����\n------------------------" );
                value = int.Parse ( Console.ReadLine ( ) );// ������ �������� � ���
                Console.WriteLine ( );

                switch ( value ) {
                    case 0:
                    break;
                    case 1:
                    student1.StudentList ( );
                    break;
                    case 2:
                    student1.GetRate ( );
                    break;
                    case 3:
                    student1.ShowMarks ( );
                    break;
                    case 4:
                    student1.MiddleMark ( );
                    break;
                    default:
                    Console.Write ( "Wrong!\n" );
                    break;
                }
            }
        }//   end main  

    }// end class Programm

}// end namecpase Classwork
