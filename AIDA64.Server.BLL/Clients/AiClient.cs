using System.Text;
using System.Text.Json;


namespace AIDA64.Server.BLL.Clients
{
    public class AiClient : IAiClient
    {
        private readonly HttpClient _httpClient = default!;
        private readonly string _systemConfig = "You are a useful assistant AIDA64. AIDA64-WinUI3 applications your goal is to help the user with the computer.";

        public AiClient(HttpClient httpClient)
        {
            _httpClient = httpClient;
        }

        public async Task<string> SendAsync(string? userMessage, CancellationToken cancellationToken = default)
        {
            if (string.IsNullOrWhiteSpace(userMessage))
                return "[ERROR] Пустое сообщение";

            var payload = new
            {
                model = "meta-llama/Llama-4-Maverick-17B-128E-Instruct-FP8",
                temperature = 0.0,
                stream = false,
                max_completion_tokens = 1000,
                messages = new[]
                {
                    new { role = "system", content = _systemConfig },
                    new { role = "user", content = userMessage }
                }
            };

            var json = JsonSerializer.Serialize(payload);
            var request = new HttpRequestMessage(HttpMethod.Post, "");
            request.Content = new StringContent(json, Encoding.UTF8, "application/json");

            try
            {
                var response = await _httpClient.SendAsync(request, cancellationToken);
                response.EnsureSuccessStatusCode();

                var responseText = await response.Content.ReadAsStringAsync(cancellationToken);
                using var doc = JsonDocument.Parse(responseText);
                var content = doc.RootElement
                    .GetProperty("choices")[0]
                    .GetProperty("message")
                    .GetProperty("content")
                    .GetString();

                return content ?? "[ERROR] Пустой ответ";
            }
            catch (Exception ex)
            {
                return "[ERROR] " + ex.Message;
            }
        }
    }
}
