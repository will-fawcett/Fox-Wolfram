#include <iostream>
#include "TLorentzVector.h"

#include "Fox_Wolfram_Calculator.h" 

int main(){


  TLorentzVector jet1, jet2, jet3, jet4, jet5, jet6;

  // Pt and E in [MeV]
  jet1.SetPtEtaPhiE(260923.687500, -0.754213, -1.222322, 339044.750000);
  jet2.SetPtEtaPhiE(205129.421875, 0.264774, 0.808242, 213544.078125);
  jet3.SetPtEtaPhiE(121481.562500, -0.431350, 2.892471, 135480.546875);
  jet4.SetPtEtaPhiE(106162.468750, 0.042144, 1.333415, 107063.742188);
  jet5.SetPtEtaPhiE(97845.046875, -0.343311, -2.523520, 105515.656250);
  jet6.SetPtEtaPhiE(55347.425781, 0.370094, 2.653073, 59491.812500);

  std::vector<TLorentzVector> jets;
  jets.push_back(jet1);
  jets.push_back(jet2);
  jets.push_back(jet3);
  jets.push_back(jet4);
  jets.push_back(jet5);
  jets.push_back(jet6);


  double moment = 0;
  for(int H_i : {1,2,3,4,5}){
    moment = calculate_moment(H_i, jets);
    std::cout << "moment(" << H_i << ") = " << moment << std::endl; 
  }

}
