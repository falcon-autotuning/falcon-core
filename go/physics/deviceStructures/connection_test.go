package devicestructures

import (
	"testing"
)

func TestConnection_ConstructorsAndAccessors(t *testing.T) {
	c2 := NewBarrierGate("foo")
	defer c2.Close()
	if c2.Name() != "foo" {
		t.Errorf("Expected name 'foo', got '%s'", c2.Name())
	}
	if c2.Type() != "BarrierGate" {
		t.Errorf("Expected type 'BarrierGate', got '%s'", c2.Type())
	}

	c3 := NewOhmic("bar")
	defer c3.Close()
	if c3.Name() != "bar" {
		t.Errorf("Expected name 'bar', got '%s'", c3.Name())
	}
	if c3.Type() != "Ohmic" {
		t.Errorf("Expected type 'Ohmic', got '%s'", c3.Type())
	}
}

func TestConnection_StaticFactories_NamesAndTypes(t *testing.T) {
	barrier := NewBarrierGate("b")
	plunger := NewPlungerGate("p")
	reservoir := NewReservoirGate("r")
	screening := NewScreeningGate("s")
	ohmic := NewOhmic("o")
	defer barrier.Close()
	defer plunger.Close()
	defer reservoir.Close()
	defer screening.Close()
	defer ohmic.Close()

	if barrier.Name() != "b" || barrier.Type() != "BarrierGate" {
		t.Error("BarrierGate name/type mismatch")
	}
	if plunger.Name() != "p" || plunger.Type() != "PlungerGate" {
		t.Error("PlungerGate name/type mismatch")
	}
	if reservoir.Name() != "r" || reservoir.Type() != "ReservoirGate" {
		t.Error("ReservoirGate name/type mismatch")
	}
	if screening.Name() != "s" || screening.Type() != "ScreeningGate" {
		t.Error("ScreeningGate name/type mismatch")
	}
	if ohmic.Name() != "o" || ohmic.Type() != "Ohmic" {
		t.Error("Ohmic name/type mismatch")
	}
}

func TestConnection_StaticFactories_FeatureChecks(t *testing.T) {
	barrier := NewBarrierGate("b")
	plunger := NewPlungerGate("p")
	reservoir := NewReservoirGate("r")
	screening := NewScreeningGate("s")
	ohmic := NewOhmic("o")
	defer barrier.Close()
	defer plunger.Close()
	defer reservoir.Close()
	defer screening.Close()
	defer ohmic.Close()

	if !barrier.IsBarrierGate() {
		t.Error("Barrier should be BarrierGate")
	}
	if !barrier.IsDotGate() {
		t.Error("Barrier should be DotGate")
	}
	if !barrier.IsGate() {
		t.Error("Barrier should be Gate")
	}
	if barrier.IsOhmic() {
		t.Error("Barrier should not be Ohmic")
	}

	if !plunger.IsPlungerGate() {
		t.Error("Plunger should be PlungerGate")
	}
	if !plunger.IsDotGate() {
		t.Error("Plunger should be DotGate")
	}
	if !plunger.IsGate() {
		t.Error("Plunger should be Gate")
	}
	if plunger.IsOhmic() {
		t.Error("Plunger should not be Ohmic")
	}

	if !reservoir.IsReservoirGate() {
		t.Error("Reservoir should be ReservoirGate")
	}
	if reservoir.IsDotGate() {
		t.Error("Reservoir should not be DotGate")
	}
	if !reservoir.IsGate() {
		t.Error("Reservoir should be Gate")
	}
	if reservoir.IsOhmic() {
		t.Error("Reservoir should not be Ohmic")
	}

	if !screening.IsScreeningGate() {
		t.Error("Screening should be ScreeningGate")
	}
	if screening.IsDotGate() {
		t.Error("Screening should not be DotGate")
	}
	if !screening.IsGate() {
		t.Error("Screening should be Gate")
	}
	if screening.IsOhmic() {
		t.Error("Screening should not be Ohmic")
	}

	if !ohmic.IsOhmic() {
		t.Error("Ohmic should be Ohmic")
	}
	if ohmic.IsGate() {
		t.Error("Ohmic should not be Gate")
	}
	if ohmic.IsDotGate() {
		t.Error("Ohmic should not be DotGate")
	}
}

func TestConnection_EqualityAndInequality(t *testing.T) {
	a := NewBarrierGate("a")
	b := NewBarrierGate("b")
	defer a.Close()
	defer b.Close()

	if a.Equal(b) {
		t.Error("a and b should not be equal")
	}
	if !a.Equal(a) {
		t.Error("a should be equal to itself")
	}
}

func TestConnection_SerializationRoundTrip(t *testing.T) {
	c := NewScreeningGate("foo")
	defer c.Close()
	json := c.ToJSON()
	c2 := ConnectionFromJSON(json)
	defer c2.Close()

	if c2.Name() != "foo" {
		t.Errorf("Expected name 'foo', got '%s'", c2.Name())
	}
	if c2.Type() != "ScreeningGate" {
		t.Errorf("Expected type 'ScreeningGate', got '%s'", c2.Type())
	}
	if !c2.IsScreeningGate() {
		t.Error("c2 should be ScreeningGate")
	}
}
