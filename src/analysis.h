#pragma once

#include <cmath>

#include "circuits.h"

class IAnalysis {
 public:
  void Run(Circuit* c) {
    load_input(c);
    perform_computations();
    generate_output();
  }

 private:
  virtual void load_input(Circuit* c) = 0;
  virtual void perform_computations() = 0;
  virtual void generate_output() = 0;
};

class HarmonicOscillator : public IAnalysis {
 private:
  double alpha = 0.0;
  double omega0 = 0.0;

 public:
  void load_input(Circuit* c) override {
    omega0 = 1.0 / std::sqrt(c->get_inductance() * c->get_capacitance());
  }
};
