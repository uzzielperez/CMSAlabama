//Uzziel Perez

class Particle{

  private: 
    double fMass; 
    double fpx; 
    double fpy; 
    double fpz;

  public: 
    //default constructor
    Particle();

    //normal constructor
    Particle(double mass, double px, double py, double pz);

    //Functions 
    double GetMass();
    double GetMomentum();
    double GetTransverseMomentum();
    double GetPhi();
    double GetEnergy();

    void SetMass(double new_mass); 
    //void SetMomentum(double new_momentum);


};
