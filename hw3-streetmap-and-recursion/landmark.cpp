
// This program exercises inheritance and polymorphism to create subclasses of Landmark objects,
// namely Restaurants, Hotels, Hotels, and Hospitals

#include <iostream>
#include <string>
using namespace std;

class Landmark {
public:
    Landmark(string name): m_name(name)
    {}
    virtual ~Landmark() = 0;
    virtual inline string icon() const = 0;
    virtual inline string color() const = 0;
    inline string name() const {
        return m_name;
    }
private:
    string m_name;
};
// Generic base class for a Landmark, only containing a name and accessor

Landmark::~Landmark() {}
// virtual dtor definition forces the user to inherit

class Restaurant: public Landmark {
public:
    Restaurant(string name, int seatingCapacity): Landmark(name), m_seatingCapacity(seatingCapacity), m_color("yellow") {
        // account for lower bounds of seating capacity and name?
        if(m_seatingCapacity < 40)
            m_icon = "small knife/fork";
        else
            m_icon = "large knife/fork";
    }
    virtual ~Restaurant() {
        cout << "Destroying the restaurant " << name() << "." << endl;
    }
    virtual inline string icon() const {
        return m_icon;
    }
    virtual inline string color() const {
        return m_color;
    }
private:
    int m_seatingCapacity;
    string m_icon;
    string m_color;
};
// Restaurant adds a seating capacity, icon, and icon color -> seating capacity is unique

class Hotel: public Landmark {
public:
    Hotel(string name): Landmark(name), m_icon("bed"), m_color("yellow")
    {}
    virtual ~Hotel() {
        cout << "Destroying the hotel " << name() << "." << endl;
    }
    virtual inline string icon() const {
        return m_icon;
    }
    virtual inline string color() const {
        return m_color;
    }
private:
    string m_icon;
    string m_color;
};
// Hotel adds an icon and icon color -> they are not unique, because
// constraints disallow mutators functions in Landmark

class Hospital: public Landmark {
public:
    Hospital(string name): Landmark(name), m_icon("H"), m_color("blue")
    {}
    virtual ~Hospital() {
        cout << "Destroying the hospital " << name() << "." << endl;
    }
    virtual inline string icon() const {
        return m_icon;
    }
    virtual inline string color() const {
        return m_color;
    }
private:
    string m_icon;
    string m_color;
};
// Hospital adds an icon and icon color -> they are not unique, because
// constraints disallow mutators in Landmark

/*void display(const Landmark* lm)
{
    cout << "Display a " << lm->color() << " " << lm->icon() << " icon for "
    << lm->name() << "." << endl;
}
// display shows the icon, color, and name of a Landmark

int main()
{
    Landmark* landmarks[4];
    landmarks[0] = new Hotel("Westwood Rest Good");
    // Restaurants have a name and seating capacity.  Restaurants with a
    // capacity under 40 have a small knife/fork icon; those with a capacity
    // 40 or over have a large knife/fork icon.
    landmarks[1] = new Restaurant("Bruin Bite", 30);
    landmarks[2] = new Restaurant("La Morsure de l'Ours", 100);
    landmarks[3] = new Hospital("UCLA Medical Center");
    
    cout << "Here are the landmarks." << endl;
    for (int k = 0; k < 4; k++)
        display(landmarks[k]);
    
    // Clean up the landmarks before exiting
    cout << "Cleaning up." << endl;
    for (int k = 0; k < 4; k++)
        delete landmarks[k];
}*/