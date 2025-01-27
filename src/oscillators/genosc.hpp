#include <complex>
#include <vector>

class Oscillator {
  protected:
    std::string           name;
    std::complex<double>  permittivity;
    std::string           material;
    std::string           type;

  public:
    // Constructor
    Oscillator(const std::string& oscillatorName) : name(oscillatorName), permittivity(0.0, 0.0), material(""), type("") {}

    // Destructor
    virtual ~Oscillator() = default;

    virtual std::vector<std::complex<double>>     compute_permittivity(const std::vector<double>& photon_energy) const;
    const std::string&                            getName() const;
    const std::string&                            getMaterial() const;
    void                                          setMaterial(const std::string& mat);
    const std::string&                            getType() const;
    void                                          setType(const std::string& oscillatorType);
};
