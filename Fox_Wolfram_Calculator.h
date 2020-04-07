#include <cmath> // contains std::legendre since c++17
#include <vector>
#include "TLorentzVector.h"
#include "legendre.h"

using namespace Storage_B; 

double calculate_summand(int degree, const TLorentzVector& particle1, const TLorentzVector& particle2);

// Probably want to replace TLV with LorentzVector
// https://root.cern.ch/doc/master/classROOT_1_1Math_1_1LorentzVector.html

double calculate_moment(int degree, std::vector<TLorentzVector> particles){

  if(particles.size() < 2){
    std::cerr << "Fox-Wolfram moments: not enough entries!" << std::endl;
    abort();
  }

  //for (auto first = particles.begin(); first != particles.end(); ++first){
  // for (auto second = first + 1; second != particles.end(); ++second){
  double sum=0;
  for(int ii=0; ii < particles.size(); ++ii){
    for(int kk= ii+1; kk<particles.size(); ++kk){
      // Your vec.at(first) is now simply *first.
      //std::cout << first->Pt() << ", " << second->Pt() << std::endl;
      sum += calculate_summand(degree, particles.at(ii), particles.at(kk));
    }
  }

  return sum;

}

double calculate_summand(int degree, const TLorentzVector& particle1, const TLorentzVector& particle2){
  double sqrt_s_MeV = 13000000.0;
  double s_MeV2 = sqrt_s_MeV*sqrt_s_MeV;
  double cos_angle = particle1.CosTheta() * particle2.CosTheta() + sin( particle1.Phi() )*sin( particle2.Phi() )*cos( particle1.DeltaPhi(particle2) );
  double summand = particle1.P() * particle2.P() * Legendre::Pn(degree, cos_angle) / s_MeV2;
  return summand;
}
