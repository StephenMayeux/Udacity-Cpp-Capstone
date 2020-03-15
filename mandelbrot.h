class Mandelbrot {
    public:
        Mandelbrot(int a, int b, int c, double d, double e, double f, double g) :
            imageWidth_(a), imageHeight_(b), maxN_(c), minR_(d), maxR_(e), minI_(f), maxI_(g) {
                verify_dimensions();
            };
        void create_image();
    private:
        void verify_dimensions();
        bool set_height(int height = 512);
        bool set_width(int width = 512);
        double map_to_real(int plot);
        double map_to_imaginary(int plot);
        int find_mandelbrot(double cr, double ci);
        int imageWidth_;
        int imageHeight_;
        int maxN_;
        double minR_;
        double maxR_;
        double minI_;
        double maxI_;
};