#include <iostream>
#include <string>
using namespace std;
class Model
{
public:
    virtual void predict(const string& input) = 0;
    virtual ~Model() = default;
};

class CNNModel : public Model
{
private:
    string modelName;
    int modelVersion;

    void preprocess(const string& input)
    {
        cout << "Preprocessing input....\n";
    }

    void runInference()
    {
        cout << "Running CNN inference....\n";
    }

    // This here upto to this point is called encapsulation, bundling data and methods together & controlling access to them
    // In this class we are hiding the modelName, modelVersion data and preprocess and runInference methods using private access specifier  
    public:
    CNNModel(string name, int version) : modelName(name), modelVersion(version) {}

    void predict(const string& input) override
    {
        preprocess(input);
        runInference();

        cout << "Prediction completed using " << modelName << " v" << modelVersion << "\n";
    }
    // This is called abstraction we are hiding the underlying complexity of the predict and only exposing predict to the outside world
    // One who is using predict dosen't need to know how it is implemented under the hood we just want to using predict function   
};

int main()
{
    CNNModel model("FaceDetector", 1);
    model.predict("image.jpg");
    // See this is called abstraction one dosen't need to know underlying concepts like how it is preprocessig, how it is running interference 
    // they simply upload and asks to predict 

    return 0;
}