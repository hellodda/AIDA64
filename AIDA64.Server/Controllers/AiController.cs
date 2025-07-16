using AIDA64.Server.BLL.Clients;
using Microsoft.AspNetCore.Mvc;
using System.Threading.Tasks;

namespace AIDA64.Server.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class AiController : ControllerBase
    {
        private readonly IAiClient _client;
        private readonly ILogger<AiController> _logger;

        public AiController(IAiClient client, ILogger<AiController> logger)
        {
            _client = client;
            _logger = logger;
        }

        [HttpGet]
        [ResponseCache(Duration = 30, Location = ResponseCacheLocation.Client)]
        public async Task<ActionResult<string>> Get([FromQuery] string? message, CancellationToken cancellationToken)
        {
            if (string.IsNullOrWhiteSpace(message))
            {
                _logger.LogWarning("AiController.Get called with empty message");
                return BadRequest("Message must not be empty.");
            }

            _logger.LogInformation("AiController.Get processing message: {Message}", message);

            var task = _client.SendAsync(message, cancellationToken);

            if (cancellationToken.IsCancellationRequested)
            {
                _logger.LogWarning("Request was cancelled by the client");
                return StatusCode(499); 
            }

            try
            {
                var result = await task;
                _logger.LogInformation("AiController.Get completed successfully");
                return Ok(result);
            }
            catch (OperationCanceledException)
            {
                _logger.LogWarning("AiClient.SendAsync was cancelled");
                return StatusCode(499);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error in AiClient.SendAsync");
                return StatusCode(500, "Internal server error.");
            }
        }
    }
}
