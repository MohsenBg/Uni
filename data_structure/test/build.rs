use bindgen;
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
        .clang_arg("-std=c++14")
        .header("wrapper.cpp")
        .allowlist_function("recursive_fac")
        .allowlist_function("iteration_fac")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .generate()
        .expect("Unable to generate bindings");
    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}
