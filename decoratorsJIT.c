#include <libgccjit.h>
#include <stdlib.h>

//global function declaration
typedef void (*fn_type) ();
fn_type printStar;

void create_code_printStar(gcc_jit_context *ctxt) {

	/**
	*	void printStar() {
	*		printf("********\n");
	*	}
	*/

	gcc_jit_type *void_type = gcc_jit_context_get_type (ctxt, GCC_JIT_TYPE_VOID);
	gcc_jit_type *int_type = gcc_jit_context_get_type( ctxt, GCC_JIT_TYPE_INT);
	gcc_jit_type *const_char_ptr_type = gcc_jit_context_get_type (ctxt, GCC_JIT_TYPE_CONST_CHAR_PTR);
	
	gcc_jit_function *func = gcc_jit_context_new_function (ctxt, NULL, GCC_JIT_FUNCTION_EXPORTED, void_type, "printStar", 0, NULL, 0);

	gcc_jit_param *param_format = gcc_jit_context_new_param(ctxt, NULL, const_char_ptr_type, "format");
	
	gcc_jit_function *printf_func = gcc_jit_context_new_function (ctxt, NULL, GCC_JIT_FUNCTION_IMPORTED, int_type, "printf", 1, &param_format, 1);
	
	gcc_jit_rvalue *args[1];
	args[0] = gcc_jit_context_new_string_literal(ctxt, "********\n");
	gcc_jit_block *block = gcc_jit_function_new_block (func, NULL);
	gcc_jit_block_add_eval (block, NULL,gcc_jit_context_new_call (ctxt, NULL, printf_func, 1, args));
	gcc_jit_block_end_with_void_return (block, NULL);
}

/*
Decorator in C
*/
void starDecor(void (*func)(char*), char * arg) {
	/*
	Do anything before function execution
	*/
	printStar();
	func(arg);
	/*
	Do anything after function execution
	*/
	printStar();
}

void welcome(char* name){
	printf("welcome %s\n",name);
}

int main(){
	gcc_jit_context *ctxt;
	gcc_jit_result *result;
	
	//	Get a "context" object for working with the library.
	ctxt = gcc_jit_context_acquire ();
	if (!ctxt)
	{
		fprintf (stderr, "NULL ctxt");
		exit (1);
	}
	
	/*	Set some options on the context.
	*	Let's see the code being generated, in assembler form.
	*/
	gcc_jit_context_set_bool_option (ctxt, GCC_JIT_BOOL_OPTION_DUMP_GENERATED_CODE, 0);

	//	Populate the context.  */
	create_code_printStar(ctxt);
	
	//	Compile the code.
	result = gcc_jit_context_compile (ctxt);
	if (!result)
	{
		fprintf (stderr, " compilation failure");
		exit (1);
	}

	//	Extract the generated code from "result".
	printStar = (fn_type) gcc_jit_result_get_code (result, "printStar");
	if (!printStar)
	{
		fprintf (stderr, "printStar function not found... check for speeling mistake");
		exit (1);
	}

	starDecor(welcome, "Headshot");
	
	fflush(stdout);
	gcc_jit_context_release (ctxt);
	gcc_jit_result_release (result);
	return 0;
}
