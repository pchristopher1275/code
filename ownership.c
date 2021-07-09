/* ownership.c generated by valac 0.42.5, the Vala compiler
 * generated from ownership.vala, do not modify */



#include <glib.h>
#include <glib-object.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <gobject/gvaluecollector.h>


#define TYPE_FOO (foo_get_type ())
#define FOO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FOO, Foo))
#define FOO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FOO, FooClass))
#define IS_FOO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FOO))
#define IS_FOO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FOO))
#define FOO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FOO, FooClass))

typedef struct _Foo Foo;
typedef struct _FooClass FooClass;
typedef struct _FooPrivate FooPrivate;
typedef struct _ParamSpecFoo ParamSpecFoo;

#define TYPE_BAR (bar_get_type ())
typedef struct _Bar Bar;
#define _foo_unref0(var) ((var == NULL) ? NULL : (var = (foo_unref (var), NULL)))

struct _Foo {
	GTypeInstance parent_instance;
	volatile int ref_count;
	FooPrivate * priv;
	gint a;
	gint b;
};

struct _FooClass {
	GTypeClass parent_class;
	void (*finalize) (Foo *self);
};

struct _ParamSpecFoo {
	GParamSpec parent_instance;
};

struct _Bar {
	gint x;
	gint y;
};


static gpointer foo_parent_class = NULL;

gpointer foo_ref (gpointer instance);
void foo_unref (gpointer instance);
GParamSpec* param_spec_foo (const gchar* name,
                            const gchar* nick,
                            const gchar* blurb,
                            GType object_type,
                            GParamFlags flags);
void value_set_foo (GValue* value,
                    gpointer v_object);
void value_take_foo (GValue* value,
                     gpointer v_object);
gpointer value_get_foo (const GValue* value);
GType foo_get_type (void) G_GNUC_CONST;
Foo* foo_new (gint a,
              gint b);
Foo* foo_construct (GType object_type,
                    gint a,
                    gint b);
static void foo_finalize (Foo * obj);
GType bar_get_type (void) G_GNUC_CONST;
Bar* bar_dup (const Bar* self);
void bar_free (Bar* self);
gint Hmmm (Bar* b);
gint _vala_main (gchar** args,
                 int args_length1);


Foo*
foo_construct (GType object_type,
               gint a,
               gint b)
{
	Foo* self = NULL;
	self = (Foo*) g_type_create_instance (object_type);
	self->a = a;
	self->b = b;
	return self;
}


Foo*
foo_new (gint a,
         gint b)
{
	return foo_construct (TYPE_FOO, a, b);
}


static void
value_foo_init (GValue* value)
{
	value->data[0].v_pointer = NULL;
}


static void
value_foo_free_value (GValue* value)
{
	if (value->data[0].v_pointer) {
		foo_unref (value->data[0].v_pointer);
	}
}


static void
value_foo_copy_value (const GValue* src_value,
                      GValue* dest_value)
{
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = foo_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer
value_foo_peek_pointer (const GValue* value)
{
	return value->data[0].v_pointer;
}


static gchar*
value_foo_collect_value (GValue* value,
                         guint n_collect_values,
                         GTypeCValue* collect_values,
                         guint collect_flags)
{
	if (collect_values[0].v_pointer) {
		Foo * object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = foo_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar*
value_foo_lcopy_value (const GValue* value,
                       guint n_collect_values,
                       GTypeCValue* collect_values,
                       guint collect_flags)
{
	Foo ** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = foo_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec*
param_spec_foo (const gchar* name,
                const gchar* nick,
                const gchar* blurb,
                GType object_type,
                GParamFlags flags)
{
	ParamSpecFoo* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TYPE_FOO), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer
value_get_foo (const GValue* value)
{
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_FOO), NULL);
	return value->data[0].v_pointer;
}


void
value_set_foo (GValue* value,
               gpointer v_object)
{
	Foo * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_FOO));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_FOO));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		foo_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		foo_unref (old);
	}
}


void
value_take_foo (GValue* value,
                gpointer v_object)
{
	Foo * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_FOO));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_FOO));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		foo_unref (old);
	}
}


static void
foo_class_init (FooClass * klass)
{
	foo_parent_class = g_type_class_peek_parent (klass);
	((FooClass *) klass)->finalize = foo_finalize;
}


static void
foo_instance_init (Foo * self)
{
	self->ref_count = 1;
}


static void
foo_finalize (Foo * obj)
{
	Foo * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_FOO, Foo);
	g_signal_handlers_destroy (self);
}


GType
foo_get_type (void)
{
	static volatile gsize foo_type_id__volatile = 0;
	if (g_once_init_enter (&foo_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { value_foo_init, value_foo_free_value, value_foo_copy_value, value_foo_peek_pointer, "p", value_foo_collect_value, "p", value_foo_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (FooClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) foo_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Foo), 0, (GInstanceInitFunc) foo_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType foo_type_id;
		foo_type_id = g_type_register_fundamental (g_type_fundamental_next (), "Foo", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&foo_type_id__volatile, foo_type_id);
	}
	return foo_type_id__volatile;
}


gpointer
foo_ref (gpointer instance)
{
	Foo * self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void
foo_unref (gpointer instance)
{
	Foo * self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		FOO_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


Bar*
bar_dup (const Bar* self)
{
	Bar* dup;
	dup = g_new0 (Bar, 1);
	memcpy (dup, self, sizeof (Bar));
	return dup;
}


void
bar_free (Bar* self)
{
	g_free (self);
}


GType
bar_get_type (void)
{
	static volatile gsize bar_type_id__volatile = 0;
	if (g_once_init_enter (&bar_type_id__volatile)) {
		GType bar_type_id;
		bar_type_id = g_boxed_type_register_static ("Bar", (GBoxedCopyFunc) bar_dup, (GBoxedFreeFunc) bar_free);
		g_once_init_leave (&bar_type_id__volatile, bar_type_id);
	}
	return bar_type_id__volatile;
}


gint
Hmmm (Bar* b)
{
	gint result = 0;
	Bar _tmp0_;
	gint _tmp1_;
	Bar _tmp2_;
	gint _tmp3_;
	g_return_val_if_fail (b != NULL, 0);
	_tmp0_ = *b;
	_tmp1_ = _tmp0_.x;
	_tmp2_ = *b;
	_tmp3_ = _tmp2_.y;
	result = _tmp1_ + _tmp3_;
	return result;
}


static gpointer
_foo_ref0 (gpointer self)
{
	return self ? foo_ref (self) : NULL;
}


gint
_vala_main (gchar** args,
            int args_length1)
{
	gint result = 0;
	Foo* f1 = NULL;
	Foo* _tmp0_;
	Foo* f2 = NULL;
	Foo* _tmp1_;
	Foo* f3 = NULL;
	FILE* _tmp2_;
	gint _tmp3_;
	gint _tmp4_;
	FILE* _tmp5_;
	gint _tmp6_;
	gint _tmp7_;
	Bar b1 = {0};
	Bar _tmp8_ = {0};
	Bar b2 = {0};
	Bar _tmp9_;
	Bar b3 = {0};
	Bar _tmp10_;
	FILE* _tmp11_;
	Bar _tmp12_;
	gint _tmp13_;
	Bar _tmp14_;
	gint _tmp15_;
	FILE* _tmp16_;
	Bar _tmp17_;
	gint _tmp18_;
	Bar _tmp19_;
	gint _tmp20_;
	_tmp0_ = foo_new (1, 2);
	f1 = _tmp0_;
	_tmp1_ = _foo_ref0 (f1);
	f2 = _tmp1_;
	f3 = f1;
	_tmp2_ = stdout;
	_tmp3_ = f3->a;
	_tmp4_ = f3->b;
	fprintf (_tmp2_, "%d %d\n", _tmp3_, _tmp4_);
	_tmp5_ = stdout;
	_tmp6_ = f2->a;
	_tmp7_ = f2->b;
	fprintf (_tmp5_, "%d %d\n", _tmp6_, _tmp7_);
	_tmp8_.x = 0;
	_tmp8_.y = 1;
	b1 = _tmp8_;
	_tmp9_ = b1;
	b2 = _tmp9_;
	b2.x = 3;
	b2.y = 4;
	_tmp10_ = b1;
	b3 = _tmp10_;
	_tmp11_ = stdout;
	_tmp12_ = b3;
	_tmp13_ = _tmp12_.x;
	_tmp14_ = b3;
	_tmp15_ = _tmp14_.y;
	fprintf (_tmp11_, "%d %d\n", _tmp13_, _tmp15_);
	_tmp16_ = stdout;
	_tmp17_ = b2;
	_tmp18_ = _tmp17_.x;
	_tmp19_ = b2;
	_tmp20_ = _tmp19_.y;
	fprintf (_tmp16_, "%d %d\n", _tmp18_, _tmp20_);
	Hmmm (&b1);
	result = 0;
	_foo_unref0 (f2);
	_foo_unref0 (f1);
	return result;
}


int
main (int argc,
      char ** argv)
{
	return _vala_main (argv, argc);
}



