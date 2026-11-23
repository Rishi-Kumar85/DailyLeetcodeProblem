
class ProductOfNumbers {
private:
    vector<int> prefix;

public:
    ProductOfNumbers() {
        prefix.push_back(1);
    }

    void add(int num) {

        // If zero arrives, reset prefix products
        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);
        }
        else {
            // Store cumulative product
            int product = prefix.back() * num;
            prefix.push_back(product);
        }
    }

    int getProduct(int k) {

        // Requested range contains a zero
        if (k >= prefix.size()) {
            return 0;
        }

        // Calculate product using prefix division
        return prefix.back() / prefix[prefix.size() - 1 - k];
    }
};
