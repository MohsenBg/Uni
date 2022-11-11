use bindgen::{self, Builder};
use std::env;
use std::path::PathBuf;
fn main() {
    cc::Build::new()
        .file("wrapper.cpp")
        .cpp(true)
        .compile("libwrapper.a");

    println!("cargo:rustc-link-search=/path/to/lib");
    println!("cargo:rerun-if-changed=wrapper.cpp");
    println!("cargo:rustc-link-lib=dylib=stdc++");

    let bindings = bindgen::Builder::default()
        .clang_arg("-x")
        .clang_arg("c++")
        .clang_arg("-std=c++20")
        .header("wrapper.cpp")
        .allowlist_function("recursive_fac")
        .allowlist_function("iteration_fac");

    let bindings = add_white_list_functions(bindings);
    let bindings = bindings
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .generate()
        .expect("Unable to generate bindings");
    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}

fn add_white_list_functions(bindings: Builder) -> Builder {
    let function_names = vec![
        //factorial
        "recursive_fac",
        "recursive_fac",
        //bubble_sort
        "bubble_sort_i16",
        "bubble_sort_i32",
        "bubble_sort_i64",
        "bubble_sort_u16",
        "bubble_sort_u32",
        "bubble_sort_u64",
        "bubble_sort_f32",
        "bubble_sort_f64",
        //insertion_sort
        "insertion_sort_i16",
        "insertion_sort_i32",
        "insertion_sort_i64",
        "insertion_sort_u16",
        "insertion_sort_u32",
        "insertion_sort_u64",
        "insertion_sort_f32",
        "insertion_sort_f64",
        // selection_sort
        "selection_sort_i16",
        "selection_sort_i32",
        "selection_sort_i64",
        "selection_sort_u16",
        "selection_sort_u32",
        "selection_sort_u64",
        "selection_sort_f32",
        "selection_sort_f64",
        // quick_sort
        "quick_sort_i16",
        "quick_sort_i32",
        "quick_sort_i64",
        "quick_sort_u16",
        "quick_sort_u32",
        "quick_sort_u64",
        "quick_sort_f32",
        "quick_sort_f64",
        // merge_sort
        "merge_sort_i16",
        "merge_sort_i32",
        "merge_sort_i64",
        "merge_sort_u16",
        "merge_sort_u32",
        "merge_sort_u64",
        "merge_sort_f32",
        "merge_sort_f64",
    ];

    let mut bindings = bindings;
    for name in function_names {
        bindings = bindings.allowlist_function(name);
    }

    bindings
}
