//
//  main.cpp
//  Academiee
//
//  Created by Анна Горячева on 22.04.2021.
//
#define DELIMETER "\n--------------------------------------------------\n"

#include <iostream>
using namespace std;

    class Human
    {
        string last_name;
        string first_name;
        unsigned int age;
    public:
      const string& get_last_name()const
        {
            return last_name;
        }
        const string& get_first_name()const
        {
            return first_name;
        }
        unsigned int get_age()const
        {
            return age;
        }
        void set_last_name(const string& last_name)
        {
            this->last_name = last_name;
        }
        void set_first_name(const string& first_name)
        {
            this->first_name = first_name;
        }
        void set_age(unsigned int age)
        {
            if(age>=15 && age<=100)
            this->age = age;
            else
                this->age = 0;
        }
        
        // Constructors
        
        Human(const string& last_name,const string& first_name, unsigned int age)
        {
            set_last_name(last_name);
            set_first_name(first_name);
            set_age(age);
            cout << "HConstructor:\t" << this << endl;
        }
        ~Human()
        {
            cout << "HDestructor:\t" << this << endl;
        }
        // Methods
        void info()const
        {
            cout << last_name << " " << first_name << ", " << age << " лет" << endl;
        }
    };

class Student:public Human
{
    string speciality;
    double rating;
    unsigned int semester;
public:
    const string& get_speciality()const
    {
        return speciality;
    }
    double get_rating()const
    {
        return rating;
    }
    unsigned int get_semester()const
    {
        return semester;
    }
    void set_speciality(const string& speciality)
    {
        this->speciality = speciality;
    }
    void set_rating(double rating)
    {
        if(rating>0 && rating <=5)
            this->rating = rating;
        else
            this->rating = 0;
    }
    void set_semester(unsigned int semester)
    {
        if(semester<=5)
            this->semester = semester;
        else
            this->semester=0;
    }
    // Constructors
    Student(
            const string& last_name, const string& first_name, unsigned int age,
            const string& speciality, double rating, unsigned int semester):Human(last_name,first_name,age)
    {
        set_speciality(speciality);
        set_rating(rating);
        set_semester(semester);
        cout << "SConstructor:\t" << this << endl;
    }
    ~Student()
    {
        cout << "SDestructor:\t" << this << endl;
    }
    
    // Methods
    void info()const
    {
        Human::info();
        cout <<"Курс: " << semester << ", Специальность: " << speciality << " , Успеваемость: " << rating << endl;
    }
};

class Teacher:public Human
{
    string speciality;
    double experience;
    unsigned int evil;
public:
    const string& get_speciality()const
    {
        return speciality;
    }
    double get_experience()const
    {
        return experience;
    }
    unsigned int get_evil()const
    {
        return evil;
    }
    void set_speciality(const string& speciality)
    {
        this->speciality = speciality;
    }
    void set_experience(double experience)
    {
        if(experience>0 && experience <=20)
            this->experience = experience;
        else
            cout << "Teacher level GOD!" << endl; /// Вот здесь бы хотелось чтоб норм работало, оно выводится.но потом(над последним делиметром выводит просто адрес
    }
    void set_evil(unsigned int evil)
    {
        if(evil<=50)
            this->evil = evil;
        else
            cout << "Danger!"<< endl;; // Здесь та же печаль,работает,но не до конца как мне надо((
    }
    // Constructors
    Teacher(
            const string& last_name, const string& first_name, unsigned int age,
            const string& speciality, double experience, unsigned int evil):Human(last_name,first_name,age)
    {
        set_speciality(speciality);
        set_experience(experience);
        set_evil(evil);
        cout << "TConstructor:\t" << this << endl;
    }
    ~Teacher()
    {
        cout << "TDestructor:\t" << this << endl;
    }
    
    // Methods
    void info()const
    {
        Human::info();
        cout <<"Опыт: " << experience << ", Специальность: " << speciality << " , Уровень злости: " << evil << endl;
    }
};

class Graduent:public Human
{
    string speciality;
    unsigned int valuation;
    string diplom_topic;
public:
    const string& get_speciality()const
    {
        return speciality;
    }
    double get_valuation()const
    {
        return valuation;
    }
    const string& get_diplom_topic()const
    {
        return diplom_topic;
    }
    void set_speciality(const string& speciality)
    {
        this->speciality = speciality;
    }
    void set_valuation(unsigned int valuation)
    {
        if(valuation>0 && valuation <=5)
            this->valuation = valuation;
        else
            this->valuation = 0;
    }
    void set_diplom_topic(const string& diplom_topic)
    {
            this->diplom_topic = diplom_topic;
    }
    // Constructors
    Graduent(
            const string& last_name, const string& first_name, unsigned int age,
            const string& speciality, unsigned int valuation, const string& diplom_topic):Human(last_name,first_name,age)
    {
        set_speciality(speciality);
        set_valuation(valuation);
        set_diplom_topic(diplom_topic);
        cout << "GConstructor:\t" << this << endl;
    }
    ~Graduent()
    {
        cout << "GDestructor:\t" << this << endl;
    }
    
    // Methods
    void info()const
    {
        Human::info();
        cout <<"Тема диплома: " << diplom_topic << ", Специальность: " << speciality << " , Оценка: " << valuation << endl;
    }
};


int main() {
    setlocale (LC_ALL, "");
//    Human vasily("Тупенко","Василий", 18);
//    vasily.info();
    Student vasily("Тупенко","Василий", 18,"Программирование",4.2,1);
    vasily.info();
    cout << DELIMETER << endl;
    Teacher valery("Гениалов","Валерий",55,"Программирование",5.5,20);
    cout << DELIMETER << endl;
    valery.info();
    cout << DELIMETER << endl;
    Graduent pavel("Счастливчиков","Павел",21,"Программирование",4,"Криптография");
    cout << DELIMETER << endl;
    pavel.info();
    cout << DELIMETER << endl;
    return 0;
}
