#ifndef _POINTSTATS_H_
#define _POINTSTATS_H_
#include <iostream>
#include "homogeneousvector4f.h"

namespace pwn {

/** \struct HomogeneousPoint3fStats
 *  \brief Class for 3D points stats representation.
 *
 *  This class extends the Eigen Matrix4f class allowing to represent some stats associated to
 *  a 3D point. In particular it is able to store the eigenvalues and eigenvectors of the covariance
 *  matrix associated to a point along with its curvature.
 */
struct PointStats : public Eigen::Matrix4f {
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW;

  /**
   *  Empty constructor.
   *  This constructor creates an HomogeneousPoint3fStats object filling the matrix with zeros.
   */
  inline PointStats() {
    _n = 0;
    setIdentity();
    _eigenValues.setZero();
    _curvatureComputed = false;
    _curvature = 1.0f;	
  }

  inline int n() { return _n; }
  inline void setN(const int n_) { _n = n_; }

  inline Point mean() { return block<4,1>(0,3); }
  inline void setMean(const Point mean_) { block<4,1>(0,3) = mean_; }

  inline const Eigen::Vector3f& eigenValues() const { return _eigenValues; }
  inline void setEigenValues(const Eigen::Vector3f& eigenValues_)  { _eigenValues = eigenValues_; }

  inline Eigen::Matrix3f eigenVectors() const { return block<3, 3>(0, 0); }
  inline void  setEigenVectors(const Eigen::Matrix3f& eigenVectors_)  { block<3, 3>(0, 0) = eigenVectors_; }

  inline float curvature() const {
    if(!_curvatureComputed)
      _curvature = _eigenValues(0) / (_eigenValues(1) + _eigenValues(1) + _eigenValues(2) + 1e-9);
    _curvatureComputed = true;
    return _curvature;
  }
  

 protected:  	
  int _n;
  Eigen::Vector3f _eigenValues;
  mutable bool  _curvatureComputed;
  mutable float _curvature;
};


class PointStatsVector: public TransformableVector<PointStats> {

 public: 
  template<typename OtherDerived>
    inline void transformInPlace(const OtherDerived& m) {
    const Eigen::Matrix4f R4 =m;
    const Eigen::Matrix3f R = R4.block<3,3>(0,0);
    /* std::cerr << "R " << std::endl; */
    /* std::cerr << R << std::endl; */
    for (size_t i = 0; i < size(); ++i) {
      /* if (i==0){ */
      /* 	std::cerr << "before " << std::endl; */
      /* 	std::cerr << at(i) << std::endl; */
      /* 	std::cerr << at(i).eigenValues().transpose() << std::endl; */

      /* } */
      at(i).block<4,4>(0,0) = R4 * at(i).block<4,4>(0,0);
      /* if (i==0){ */
      /* 	std::cerr << "after " << std::endl; */
      /* 	std::cerr << at(i) << std::endl; */
      /* 	std::cerr << at(i).eigenValues().transpose() << std::endl; */
      /* } */
	
    }
  }


};

}

#endif