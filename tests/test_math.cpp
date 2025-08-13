#include "falcon_core/generic/OneToOneMapping.hpp"
#include "falcon_core/math/Axes.hpp"
#include "falcon_core/math/Quantity.hpp"
#include "falcon_core/math/arrays/BaseArray.hpp"
#include "falcon_core/math/arrays/ControlArray.hpp"
#include "falcon_core/math/arrays/MeasuredArray.hpp"
#include "falcon_core/math/domains/Domain.hpp"
#include "falcon_core/physics/units/Dimension.hpp"
#include "falcon_core/physics/units/SymbolUnit.hpp"
#include "falcon_core/physics/units/Unit.hpp"

#include <Eigen/Dense>
#include <gtest/gtest.h>
#include <memory>

using namespace falcon_core;

// TEST (DomainTest, ConstructionAndAccessors)
// {
//   Domain d (0.0, 5.0);
//   ASSERT_DOUBLE_EQ (d.min (), 0.0);
//   ASSERT_DOUBLE_EQ (d.max (), 5.0);
//   ASSERT_DOUBLE_EQ (d.range (), 5.0);
//
//   ASSERT_THROW (Domain (5.0, 0.0), std::invalid_argument);
// }
//
// TEST (DomainTest, Serialization)
// {
//   Domain         d (1.0, 10.0);
//   nlohmann::json j = d.to_json ();
//   ASSERT_EQ (j["__module__"], "falcon_core.math.domains.domain");
//   ASSERT_EQ (j["__class__"], "Domain");
//   ASSERT_EQ (j["_min"], 1.0);
//   ASSERT_EQ (j["_max"], 10.0);
// }
//
// TEST (QuantityTest, ConstructionAndAccessors)
// {
//   auto unit = std::make_shared<Unit> (
//       1.0, std::map<std::string, int>{ { "LENGTH", 1 } });
//   auto symbol_unit = std::make_shared<SymbolUnit> (unit, "m");
//
//   Quantity<double> q (12.5, symbol_unit);
//   ASSERT_DOUBLE_EQ (q.value (), 12.5);
//   ASSERT_EQ (q.unit ()->symbol (), "m");
// }
//
// TEST (OneToOneMappingTest, InsertionAndLookup)
// {
//   OneToOneMapping<std::string, int> o2o;
//   o2o.insert ("one", 1);
//   o2o.insert ("two", 2);
//
//   ASSERT_EQ (o2o.at_key ("one"), 1);
//   ASSERT_EQ (o2o.at_value (2), "two");
//
//   ASSERT_THROW (o2o.insert ("one", 3), std::invalid_argument);
//   ASSERT_THROW (o2o.insert ("three", 1), std::invalid_argument);
// }
//
// TEST (ArrayTest, ConstructionAndData)
// {
//   Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> m (2, 2);
//   m << 1, 2, 3, 4;
//
//   BaseArray<double> ba (m);
//   ASSERT_EQ (ba.data (), m);
//
//   ControlArray<double> ca (m);
//   ASSERT_EQ (ca.data (), m);
//
//   MeasuredArray<double> ma (m);
//   ASSERT_EQ (ma.data (), m);
// }
//
// TEST (ArrayTest, Is1D)
// {
//   Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> row_vec (1, 5);
//   Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> col_vec (5, 1);
//   Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix (2, 2);
//
//   BaseArray<double> ba_row (row_vec);
//   ASSERT_TRUE (ba_row.is_1d ());
//
//   BaseArray<double> ba_col (col_vec);
//   ASSERT_TRUE (ba_col.is_1d ());
//
//   BaseArray<double> ba_mat (matrix);
//   ASSERT_FALSE (ba_mat.is_1d ());
// }
//
// TEST (AxesTest, AppendAndAccess)
// {
//   auto d1 = std::make_shared<Domain> (0, 1);
//   auto d2 = std::make_shared<Domain> (1, 2);
//
//   Axes<Domain> axes;
//   axes.append (d1);
//   axes.append (d2);
//
//   ASSERT_EQ (axes.size (), 2);
//   ASSERT_EQ (axes.at (0), d1);
//   ASSERT_EQ (axes.at (1), d2);
//   ASSERT_FALSE (axes.empty ());
// }
//
// #include "falcon_core/physics/device_structures/BaseConnection.hpp"
// #include "falcon_core/math/domains/CoupledLabelledDomain.hpp"
// #include "falcon_core/math/domains/LabelledDomain.hpp"
//
// TEST (LabelledDomainTest, ConstructionAndAccessors)
// {
//   auto label = std::make_shared<BaseConnection> ("my_label");
//   LabelledDomain<BaseConnection> ld (0.0, 10.0, label);
//
//   ASSERT_DOUBLE_EQ (ld.min (), 0.0);
//   ASSERT_EQ (ld.label ()->name (), "my_label");
//
//   nlohmann::json j = ld.to_json ();
//   ASSERT_EQ (j["__class__"], "LabelledDomain");
//   ASSERT_TRUE (j.contains ("_label"));
// }
//
// TEST (CoupledLabelledDomainTest, ConstructionAndAccessors)
// {
//   auto label1 = std::make_shared<BaseConnection> ("label1");
//   auto coupled_domain
//       = std::make_shared<LabelledDomain<BaseConnection>> (0, 5, label1);
//
//   auto main_label = std::make_shared<BaseConnection> ("main_label");
//   std::vector<std::shared_ptr<LabelledDomain<BaseConnection>>> coupled_vec;
//   coupled_vec.push_back (coupled_domain);
//
//   CoupledLabelledDomain<BaseConnection> cld (0, 10, main_label,
//   coupled_vec);
//
//   ASSERT_EQ (cld.coupled_domains ().size (), 1);
//   ASSERT_EQ (cld.coupled_domains ()[0]->label ()->name (), "label1");
//
//   nlohmann::json j = cld.to_json ();
//   ASSERT_EQ (j["__class__"], "CoupledLabelledDomain");
//   ASSERT_TRUE (j.contains ("_coupled_domains"));
// }
//
// #include "falcon_core/math/labelled_arrays/BaseLabelledArrays.hpp"
// #include "falcon_core/physics/device_structures/Gate.hpp"
// #include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
// #include "falcon_core/math/labelled_arrays/LabelledControlArray1D.hpp"
//
// TEST (LabelledControlArray1DTest, ConstructionAndGetStart)
// {
//   Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> m (1, 3);
//   m << 10.0, 20.0, 30.0;
//   auto array = std::make_shared<ControlArray1D> (m);
//
//   auto instrument = std::shared_ptr<Instrument> (); // Null for testing
//   auto gate       = std::make_shared<Gate> ("g1");
//   auto port       = std::make_shared<InstrumentPort<Gate>> (
//       "port1", gate, instrument, "desc");
//
//   LabelledControlArray1D lca (array, port);
//
//   ASSERT_DOUBLE_EQ (lca.get_start (), 10.0);
//   ASSERT_EQ (lca.label ()->default_name (), "port1");
// }
//
// TEST (BaseLabelledArraysTest, AppendAndAccess)
// {
//   Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> m (1, 2);
//   m << 1.0, 2.0;
//   auto array      = std::make_shared<ControlArray1D> (m);
//   auto instrument = std::shared_ptr<Instrument> ();
//   auto gate       = std::make_shared<Gate> ("g1");
//   auto port       = std::make_shared<InstrumentPort<Gate>> (
//       "port1", gate, instrument, "desc");
//   auto lca = std::make_shared<LabelledControlArray1D> (array, port);
//
//   BaseLabelledArrays<LabelledControlArray1D> arrays;
//   arrays.append (lca);
//
//   ASSERT_EQ (arrays.get_arrays ().size (), 1);
//   ASSERT_EQ (arrays.get_arrays ()[0], lca);
// }
//
// #include "falcon_core/math/arrays/ControlArray1D.hpp"
// #include "falcon_core/math/arrays/IncreasingAlignment.hpp"
//
// TEST (IncreasingAlignmentTest, Construction)
// {
//   IncreasingAlignment ia;
//   nlohmann::json      j = ia.to_json ();
//   ASSERT_EQ (j["__class__"], "IncreasingAlignment");
// }
//
// TEST (ControlArray1DTest, Construction)
// {
//   Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> m (1, 3);
//   m << 1.0, 2.0, 3.0;
//   ControlArray1D ca1d (m);
//   ASSERT_TRUE (ca1d.is_1d ());
//
//   Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> m_bad (2, 2);
//   m_bad << 1, 2, 3, 4;
//   ASSERT_THROW (ControlArray1D (m_bad), std::invalid_argument);
// }
