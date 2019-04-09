/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);


    // VARIABLES:
    //distance
    PhysicalNumber dcm(100, Unit::CM);
    PhysicalNumber dm(1, Unit::M);
    PhysicalNumber dm2(1000, Unit::M);
    PhysicalNumber dkm(1, Unit::KM);
    PhysicalNumber cm5(5, Unit::CM);
    PhysicalNumber m5(5, Unit::M);
    PhysicalNumber km5(5, Unit::KM);
    
    //time
    PhysicalNumber ts(60, Unit::SEC);
    PhysicalNumber tm(1, Unit::MIN);
    PhysicalNumber tm2(60, Unit::MIN);
    PhysicalNumber th(1, Unit::HOUR);
    PhysicalNumber sec5(5, Unit::SEC);
    PhysicalNumber min5(5, Unit::MIN);
    PhysicalNumber hour5(5, Unit::HOUR);
    //mass
    PhysicalNumber mg(1000, Unit::G);
    PhysicalNumber mkg(1, Unit::KG);
    PhysicalNumber mkg2(1000, Unit::KG);
    PhysicalNumber mt(1, Unit::TON);
    PhysicalNumber g5(5, Unit::G);
    PhysicalNumber kg5(5, Unit::KG);
    PhysicalNumber t5(5, Unit::TON);




    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT


    
      

      .setname("Compatible dimensions")
      //distance:
      .CHECK_EQUALS(dcm==dm, true);
      .CHECK_EQUALS(dm2==dkm, true);
      .CHECK_EQUALS(dkm==dm2, true);
      .CHECK_EQUALS(dm==dc, true);
      //time:
      .CHECK_EQUALS(ts==tm, true);
      .CHECK_EQUALS(tm2==th, true);
      .CHECK_EQUALS(th==tm2, true);
      .CHECK_EQUALS(tm==ts, true);
      //mass:
      .CHECK_EQUALS(mg==mkg, true);
      .CHECK_EQUALS(mkg2==mt, true);
      .CHECK_EQUALS(mt==mkg2, true);
      .CHECK_EQUALS(mkg==mg, true);

      .setname("Math calculations")
      .CHECK_OUTPUT((dcm+=dm), "200[cm]")
      .CHECK_OUTPUT(dcm), "200[cm]")
      .CHECK_OUTPUT(dkm+dcm, "2.002[km]")
      .CHECK_OUTPUT(dm+dm2, "1001[m]")
      .CHECK_OUTPUT(dcm+=dcm, "400[cm]")
      .CHECK_OUTPUT(dcm+km5, "500400[cm]")
      .CHECK_OUTPUT((dcm++), "500401[cm]")
      .CHECK_OUTPUT(dcm-m5, "-100[cm]")
      .CHECK_OUTPUT(m5-dcm, "100[cm]")
      

      .setname("Compatible dimensions")
      .CHECK_EQUALS(mg==mkg, true);
      .CHECK_EQUALS(mkg2==mt, true);
      .CHECK_EQUALS(mt==mkg2, true);
      .CHECK_EQUALS(mkg==mg, true);
      .CHECK_EQUALS(mg==mkg, true);
      .CHECK_EQUALS(mkg2==mt, true);
      .CHECK_EQUALS(mt==mkg2, true);
      .CHECK_EQUALS(mkg==mg, true);
      .CHECK_EQUALS(mg==mkg, true);
      .CHECK_EQUALS(mkg2==mt, true);
      .CHECK_EQUALS(mt==mkg2, true);
      .CHECK_EQUALS(mkg==mg, true);




      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
