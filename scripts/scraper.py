import requests
from bs4 import BeautifulSoup

def Scrape(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.content, 'html.parser')
    return soup

soup = Scrape('https://www.bbc.com/')

body = soup.find("article")

paragraphs = [
    p.get_text(strip=True)
    for p in body.find_all("p", attrs={"data-compnent": "text-block"})
]

for i in paragraphs:
    print(i)