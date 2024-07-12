import requests
from bs4 import BeautifulSoup
import pandas as pd

# Define the URL
url = "https://www.amazon.co.za/dp/B0CM5X5592?th=1"

# Headers to mimic a browser visit
headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36"
}

# Make a request to fetch the page content
response = requests.get(url, headers=headers)

# Check if the request was successful
if response.status_code == 200:
    soup = BeautifulSoup(response.content, "html.parser")

    # Extract product name
    product_name = soup.find("span", id="productTitle").get_text(strip=True)
    
    # Extract price
    price = soup.find("span", class_="a-price-whole").get_text(strip=True) + soup.find("span", class_="a-price-fraction").get_text(strip=True)
    
    # Extract discount (if available)
    discount = soup.find("span", class_="savingsPercentage")
    discount = discount.get_text(strip=True) if discount else "No discount"

    # Extract ratings
    rating = soup.find("span", class_="a-icon-alt").get_text(strip=True)

    # Prepare data for CSV
    data = {
        "Product Name": [product_name],
        "Price": [price],
        "Discount": [discount],
        "Rating": [rating]
    }

    # Create DataFrame
    df = pd.DataFrame(data)

    # Save to CSV
    df.to_csv("product_info.csv", index=False)

    print("Data saved to product_info.csv")
else:
    print(f"Failed to retrieve the page. Status code: {response.status_code}")
